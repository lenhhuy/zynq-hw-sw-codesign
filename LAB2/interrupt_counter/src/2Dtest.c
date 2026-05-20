/* interrupt_counter.c — Tutorial 2D cho Zybo Z7
 * Vitis Unified IDE 2025.2 — SDT flow.
 *
 * Hai nguồn interrupt qua Concat → IRQ_F2P[1:0]:
 *   - BTN_Intr_Handler: cộng giá trị nút vào counter, ghi ra LED.
 *   - TMR_Intr_Handler: cứ 3 lần timer tràn thì counter +1, in ra UART.
 */

#include "xparameters.h"
#include "xgpio.h"
#include "xscugic.h"
#include "xtmrctr.h"
#include "xil_exception.h"
#include "xil_printf.h"

/* ---- SDT flow: BaseAddress thay cho DeviceID ---- */
#define BTN_BASEADDR            XPAR_AXI_GPIO_0_BASEADDR
#define LED_BASEADDR            XPAR_AXI_GPIO_1_BASEADDR
#define TMR_BASEADDR            XPAR_AXI_TIMER_0_BASEADDR
#define INTC_BASEADDR           XPAR_XSCUGIC_0_BASEADDR

#define INTC_GPIO_INTERRUPT_ID  XPAR_FABRIC_AXI_GPIO_0_INTR
#define INTC_TMR_INTERRUPT_ID   XPAR_FABRIC_AXI_TIMER_0_INTR
/* Nếu compiler báo macro INTC_TMR_INTERRUPT_ID không tìm thấy,
 * mở xparameters.h và đổi cho khớp — có thể là
 *   XPAR_FABRIC_AXI_TIMER_0_INTERRUPT_INTR
 * tùy phiên bản sinh code. */

#define BTN_INT     XGPIO_IR_CH1_MASK
#define BTN_CHANNEL 1
#define LED_CHANNEL 1
#define TMR_CNTR_0  0

/* Giá trị nạp cho timer (down-count). 0xF8000000 ≈ 4.16M ticks
 * tại clock PL 100 MHz ≈ 41 ms/lần tràn — đổi tuỳ ý.
 * Nếu muốn ~5 giây tại 100 MHz, dùng 5*100_000_000 = 0x1DCD6500. */
#define TMR_LOAD    0xF8000000U

static XGpio    BTNInst, LEDInst;
static XTmrCtr  TMRInst;
static XScuGic  INTCInst;

static int btn_value;
static int tmr_count = 0;
static int led_data  = 0;

/* ============================================================ */
/* Handler 1: nút nhấn                                           */
/* ============================================================ */
void BTN_Intr_Handler(void *InstancePtr)
{
    (void)InstancePtr;

    XGpio_InterruptDisable(&BTNInst, BTN_INT);

    if ((XGpio_InterruptGetStatus(&BTNInst) & BTN_INT) != BTN_INT) {
        return;
    }

    btn_value = XGpio_DiscreteRead(&BTNInst, BTN_CHANNEL);
    led_data  = led_data + btn_value;
    XGpio_DiscreteWrite(&LEDInst, LED_CHANNEL, led_data);

    (void)XGpio_InterruptClear(&BTNInst, BTN_INT);
    XGpio_InterruptEnable(&BTNInst, BTN_INT);
}

/* ============================================================ */
/* Handler 2: AXI Timer                                          */
/* Driver xtmrctr tự call handler này từ ISR chính của nó.       */
/* ============================================================ */
void TMR_Intr_Handler(void *CallBackRef, u8 TmrCtrNumber)
{
    XTmrCtr *tmr = (XTmrCtr *)CallBackRef;

    if (XTmrCtr_IsExpired(tmr, TmrCtrNumber)) {
        tmr_count++;
        if (tmr_count >= 3) {
            led_data++;
            XGpio_DiscreteWrite(&LEDInst, LED_CHANNEL, led_data);
            xil_printf("Timer tick x3 -> counter = %d\r\n", led_data);
            tmr_count = 0;
        }
    }
}

/* ============================================================ */
/* Bật exception ở mức ARM CPU                                   */
/* ============================================================ */
static int InterruptSystemSetup(XScuGic *XScuGicInstancePtr)
{
    Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
        (Xil_ExceptionHandler)XScuGic_InterruptHandler, XScuGicInstancePtr);
    Xil_ExceptionEnable();
    return XST_SUCCESS;
}

/* ============================================================ */
/* Init GIC + connect 2 handler                                  */
/* ============================================================ */
static int IntcInit(UINTPTR BaseAddr)
{
    XScuGic_Config *cfg;
    int status;

    /* SDT: LookupConfig nhận BaseAddress */
    cfg = XScuGic_LookupConfig(BaseAddr);
    if (cfg == NULL) return XST_FAILURE;

    status = XScuGic_CfgInitialize(&INTCInst, cfg, cfg->CpuBaseAddress);
    if (status != XST_SUCCESS) return XST_FAILURE;

    /* ---- GPIO button interrupt ---- */
    XScuGic_SetPriorityTriggerType(&INTCInst, INTC_GPIO_INTERRUPT_ID,
                                   0xA0, 0x3);
    status = XScuGic_Connect(&INTCInst, INTC_GPIO_INTERRUPT_ID,
                             (Xil_ExceptionHandler)BTN_Intr_Handler,
                             (void *)&BTNInst);
    if (status != XST_SUCCESS) return XST_FAILURE;
    XScuGic_Enable(&INTCInst, INTC_GPIO_INTERRUPT_ID);

    /* ---- Timer interrupt (priority cao hơn — 0x60) ---- */
    XScuGic_SetPriorityTriggerType(&INTCInst, INTC_TMR_INTERRUPT_ID,
                                   0x60, 0x3);
    status = XScuGic_Connect(&INTCInst, INTC_TMR_INTERRUPT_ID,
                             (Xil_ExceptionHandler)XTmrCtr_InterruptHandler,
                             (void *)&TMRInst);
    if (status != XST_SUCCESS) return XST_FAILURE;
    XScuGic_Enable(&INTCInst, INTC_TMR_INTERRUPT_ID);

    /* Bật mask trong AXI GPIO IP */
    XGpio_InterruptEnable(&BTNInst, BTN_INT);
    XGpio_InterruptGlobalEnable(&BTNInst);

    return InterruptSystemSetup(&INTCInst);
}

/* ============================================================ */
/* main                                                          */
/* ============================================================ */
int main(void)
{
    int status;
    xil_printf("\r\n--- Tutorial 2D: 2 interrupt sources on Zybo Z7 (SDT) ---\r\n");

    /* GPIO buttons */
    status = XGpio_Initialize(&BTNInst, BTN_BASEADDR);
    if (status != XST_SUCCESS) return XST_FAILURE;
    XGpio_SetDataDirection(&BTNInst, BTN_CHANNEL, 0xFF);

    /* GPIO LEDs */
    status = XGpio_Initialize(&LEDInst, LED_BASEADDR);
    if (status != XST_SUCCESS) return XST_FAILURE;
    XGpio_SetDataDirection(&LEDInst, LED_CHANNEL, 0x00);
    XGpio_DiscreteWrite(&LEDInst, LED_CHANNEL, 0x0);

    /* AXI Timer */
    status = XTmrCtr_Initialize(&TMRInst, TMR_BASEADDR);
    if (status != XST_SUCCESS) return XST_FAILURE;

    XTmrCtr_SetHandler(&TMRInst, TMR_Intr_Handler, &TMRInst);
    XTmrCtr_SetResetValue(&TMRInst, TMR_CNTR_0, TMR_LOAD);
    XTmrCtr_SetOptions(&TMRInst, TMR_CNTR_0,
        XTC_INT_MODE_OPTION | XTC_AUTO_RELOAD_OPTION | XTC_DOWN_COUNT_OPTION);

    /* Init GIC + connect handlers */
    if (IntcInit(INTC_BASEADDR) != XST_SUCCESS) return XST_FAILURE;

    /* Cho timer chạy */
    XTmrCtr_Start(&TMRInst, TMR_CNTR_0);

    while (1) {
        /* tất cả xử lý nằm trong 2 handler */
    }
    return 0;
}

/*
 * LED_test_zybo.c
 *
 * Adapted from The Zynq Book Tutorial 1C for ZyBo + Vitis 2025.2
 *
 *  - Works with both legacy SDK BSP and new Vitis Unified SDT-based BSP
 *  - Targets 4 LEDs on ZyBo (instead of 8 on ZedBoard)
 */

#include "xparameters.h"
#include "xgpio.h"
#include "xstatus.h"
#include "xil_printf.h"

/* ----- Tự động chọn ID/BASEADDR theo BSP -------------------------------- */
#ifdef XPAR_AXI_GPIO_0_DEVICE_ID
    /* BSP cũ (SDK / Vitis Classic) — Initialize bằng Device ID */
    #define GPIO_DEVICE_ID  XPAR_AXI_GPIO_0_DEVICE_ID
    #define USE_LEGACY_API  1
#elif defined(XPAR_AXI_GPIO_0_BASEADDR)
    /* BSP mới (Vitis Unified 2024+) — Initialize bằng Base Address */
    #define GPIO_BASEADDR   XPAR_AXI_GPIO_0_BASEADDR
    #define USE_LEGACY_API  0
#elif defined(XPAR_XGPIO_0_BASEADDR)
    /* BSP mới phiên bản khác — tên macro có "XGPIO" thay vì "AXI_GPIO" */
    #define GPIO_BASEADDR   XPAR_XGPIO_0_BASEADDR
    #define USE_LEGACY_API  0
#else
    #error "Khong tim thay AXI GPIO trong xparameters.h - kiem tra Block Design!"
#endif

/* ----- Cấu hình LED cho ZyBo (4 LEDs) ----------------------------------- */
#define LED          0x05    /* 0101 - LED0 & LED2 sang */
#define LED_DELAY    10000000
#define LED_CHANNEL  1
#define printf       xil_printf

XGpio Gpio;

int LEDOutputExample(void)
{
    volatile int Delay;
    int Status;
    int led = LED;

    /* Khoi tao GPIO driver - chon API tuy phien ban BSP */
#if USE_LEGACY_API
    Status = XGpio_Initialize(&Gpio, GPIO_DEVICE_ID);
#else
    Status = XGpio_Initialize(&Gpio, GPIO_BASEADDR);
#endif

    if (Status != XST_SUCCESS) {
        xil_printf("XGpio_Initialize failed!\r\n");
        return XST_FAILURE;
    }

    /* Set huong tat ca 4 LED la output (bit 0 = output) */
    XGpio_SetDataDirection(&Gpio, LED_CHANNEL, 0x0);

    xil_printf("ZyBo LED blink demo - khoi dong\r\n");

    /* Vong lap nhap nhay */
    while (1) {
        /* Ghi gia tri ra LED - chi 4 bit thap co tac dung */
        XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, led & 0xF);

        /* Dao trang thai LED */
        led = ~led;

        /* Delay phan mem */
        for (Delay = 0; Delay < LED_DELAY; Delay++);
    }

    return XST_SUCCESS;  /* Khong bao gio toi day */
}

int main(void)
{
    int Status;

    Status = LEDOutputExample();
    if (Status != XST_SUCCESS) {
        xil_printf("GPIO output to the LEDs failed!\r\n");
    }

    return 0;
}
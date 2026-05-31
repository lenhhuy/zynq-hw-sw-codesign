#include "xparameters.h"
#include "xil_io.h"
#include "xil_printf.h"

/* Base address lấy từ xparameters.h của bạn */
#define LED_BASE   XPAR_MY_COUNTER_0_BASEADDR
#define LED_LIMIT  255
#define DELAY      10000000

int main(void) {
    u32 led_val = 0;
    int i = 0;

    xil_printf("led_controller IP test begin.\r\n");
    xil_printf("--------------------------------------------\r\n\n");

    while (1) {
        while (led_val <= LED_LIMIT) {
            xil_printf("LED value: %d\r\n", led_val);

            /* Thay LED_CONTROLLER_mWriteReg bằng Xil_Out32 — kết quả giống nhau */
            Xil_Out32(LED_BASE, led_val);

            led_val++;
            for (i = 0; i < DELAY; i++);
        }
        led_val = 0;
    }
    return 1;
}
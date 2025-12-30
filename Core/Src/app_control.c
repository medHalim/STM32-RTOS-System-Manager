#include "app_control.h"
#include "main.h"        // HAL handles & GPIO defines
#include "cmsis_os2.h"
#include "FreeRTOS.h"

/* ===== Control Task Definition ===== */

const osThreadAttr_t ControlTask_attributes = {
    .name = "ControlTask",
    .priority = (osPriority_t) osPriorityHigh,
    .stack_size = 256 * 4
};

void ControlTask(void *argument)
{
    (void)argument;

    uint32_t nextWake = osKernelGetTickCount();
    uint16_t ledCounter = 0;

    for (;;)
    {
        // ===== Real control logic =====
        // TODO: read sensors / compute actuators

        // ===== LED for human visibility =====
        ledCounter++;
        if (ledCounter >= 50)  // 50 * 10 ms = 500 ms
        {
            HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
            ledCounter = 0;
        }

        // ===== Periodic wait (10 ms) =====
        nextWake += 10;           // 10 ms period
        osDelayUntil(nextWake);   // CMSIS-RTOS v2 API only
    }
}

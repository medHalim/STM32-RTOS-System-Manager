#include "app_monitor.h"
#include "main.h"
#include "cmsis_os2.h"

const osThreadAttr_t MonitorTask_attributes = {
    .name = "MonitorTask",
    .priority = osPriorityNormal,
    .stack_size = 256 * 4
};

void MonitorTask(void *argument)
{
    (void)argument;

    uint32_t nextWake = osKernelGetTickCount();
    uint8_t heartbeatCounter = 0;

    for (;;)
    {
        // ===== CPU load measurement / health check =====
        // TODO: implement idle counter if desired

        // ===== Heartbeat LED =====
        heartbeatCounter++;
        if (heartbeatCounter >= 10)  // 10 * 100 ms = 1 s
        {
            HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
            heartbeatCounter = 0;
        }

        // ===== Periodic wait (100 ms) =====
        nextWake += 100;          // 100 ms period
        osDelayUntil(nextWake);   // CMSIS-RTOS v2 API only
    }
}

#include "app_comm.h"
#include "cmsis_os2.h"
#include "main.h"

const osThreadAttr_t CommTask_attributes = {
    .name = "CommTask",
    .priority = osPriorityAboveNormal,
    .stack_size = 256 * 4
};

void CommTask(void *argument)
{
    (void)argument;

    for (;;)
    {
        // Wait for ISR or another task to signal communication event
        osThreadFlagsWait(0x0001, osFlagsWaitAny, osWaitForever);

        // ===== Communication handling logic =====
        // e.g., read UART / CAN / process message
        // Must finish <2 ms WCET
    }
}

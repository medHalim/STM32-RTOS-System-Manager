#include "app_fault.h"
#include "cmsis_os2.h"

const osThreadAttr_t FaultTask_attributes = {
    .name = "FaultTask",
    .priority = osPriorityRealtime,
    .stack_size = 256 * 4
};

void FaultManagerTask(void *argument)
{
    (void)argument;

    for (;;)
    {
        // Wait for notification from ISR or other task
        osThreadFlagsWait(0x0001, osFlagsWaitAny, osWaitForever);

        // ===== Fault handling logic =====
        // TODO: handle faults within <2 ms WCET
    }
}

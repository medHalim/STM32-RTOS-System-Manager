#include "app_rtos.h"
#include "cmsis_os2.h"
#include "app_control.h"
#include "app_monitor.h"
#include "app_fault.h"
#include "app_logging.h"
#include "app_comm.h"

/**
  * @brief  Initialize and create all RTOS tasks and objects
  * 
  * | Task              | Type     | Trigger                               |
  * | ----------------- | -------- | ------------------------------------- |
  * | Control_Task      | Periodic | osDelayUntil                          |
  * | Monitor_Task      | Periodic | osDelayUntil                          |
  * | FaultManager_Task | Event    | osThreadFlagsWait                     |
  * | Comm_Task         | Event    | osThreadFlagsWait (ISR-triggered)     |
  * | Logging_Task      | Event    | osMessageQueueGet / put (best-effort) |

  * @param  None
  * @retval None
  */

void App_RTOS_Init(void)
{
    // Initialize queues first
    Logging_Init();

    /* Create Control Task */
    osThreadNew(ControlTask, NULL, &ControlTask_attributes);
    osThreadNew(MonitorTask, NULL, &MonitorTask_attributes);
    osThreadNew(FaultManagerTask, NULL, &FaultTask_attributes);
    osThreadNew(LoggingTask, NULL, &LoggingTask_attributes);
    osThreadNew(CommTask, NULL, &CommTask_attributes);

    // Additional RTOS objects (semaphores, queues, etc.) can be created here
}

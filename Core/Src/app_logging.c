#include "app_logging.h"
#include "cmsis_os2.h"
#include <string.h>

#define LOG_QUEUE_SIZE 16

const osThreadAttr_t LoggingTask_attributes = {
    .name = "LoggingTask",
    .priority = osPriorityLow,
    .stack_size = 256 * 4
};

/* Message queue handle */
osMessageQueueId_t logQueueHandle;

void LoggingTask(void *argument)
{
    (void)argument;
    char msg[64];

    for (;;)
    {
        // Wait for message (best-effort)
        if (osMessageQueueGet(logQueueHandle, &msg, NULL, osWaitForever) == osOK)
        {
            // ===== Logging action =====
            // e.g., send to UART, store in buffer
        }
    }
}

/* API to push log */
void Logging_Send(const char *message)
{
    if (logQueueHandle)
    {
        osMessageQueuePut(logQueueHandle, message, 0, 0); // best-effort
    }
}

/* Initialize log queue */
void Logging_Init(void)
{
    logQueueHandle = osMessageQueueNew(LOG_QUEUE_SIZE, sizeof(char[64]), NULL);
}

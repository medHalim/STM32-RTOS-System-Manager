#ifndef APP_LOGGING_H
#define APP_LOGGING_H

#include "cmsis_os2.h"

extern const osThreadAttr_t LoggingTask_attributes;

void LoggingTask(void *argument);
void Logging_Send(const char *message);
void Logging_Init(void);

#endif /* APP_LOGGING_H */
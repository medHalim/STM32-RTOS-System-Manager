#ifndef APP_MONITOR_H
#define APP_MONITOR_H

#include "cmsis_os2.h"

/* Task attributes */
extern const osThreadAttr_t MonitorTask_attributes;

/* Task entry */
void MonitorTask(void *argument);

/* CPU load API */
uint8_t Monitor_GetCpuLoad(void);

#endif /* APP_MONITOR_H */

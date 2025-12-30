#ifndef APP_FAULT_H
#define APP_FAULT_H

#include "cmsis_os2.h"

extern const osThreadAttr_t FaultTask_attributes;

void FaultManagerTask(void *argument);

#endif /* APP_FAULT_H */
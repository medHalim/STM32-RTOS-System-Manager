#ifndef APP_CONTROL_H
#define APP_CONTROL_H

#include "cmsis_os2.h"

/* Task attributes */
extern const osThreadAttr_t ControlTask_attributes;

/* Task entry function */
void ControlTask(void *argument);

#endif /* APP_CONTROL_H */

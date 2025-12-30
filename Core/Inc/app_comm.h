#ifndef APP_COMM_H
#define APP_COMM_H
#include "cmsis_os2.h"

extern const osThreadAttr_t CommTask_attributes;

void CommTask(void *argument);

#endif /* APP_COMM_H */
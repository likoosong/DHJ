#ifndef __WATCHDOG_H
#define __WATCHDOG_H

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_iwdg.h"

/* 看门狗超时时间 (ms) */
#define IWDG_TIMEOUT 1000

/* 函数声明 */
void WATCHDOG_Init(void);
void WATCHDOG_Refresh(void);

#endif /* __WATCHDOG_H */
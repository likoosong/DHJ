/**
  * @file    pvd.h
  * @brief   Header for PVD (Programmable Voltage Detector) configuration
  * @author  Your Name
  */

#ifndef __PVD_H__
#define __PVD_H__

#include "stm32f1xx_hal.h"

/* PVD配置 */
#define PVD_LEVEL PWR_PVDLEVEL_7  // 2.9V阈值 (可根据需要调整)

/* 函数声明 */
void PVD_Init(void);
void PVD_IRQHandler(void);

#endif /* __PVD_H__ */
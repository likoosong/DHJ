#include "main.h"
#include "watchdog.h"

IWDG_HandleTypeDef hiwdg;  // 将句柄定义为全局变量

/* 独立看门狗初始化 */
void WATCHDOG_Init(void)
{
    /* 对于STM32F1系列，IWDG使用独立的LSI时钟，不需要额外使能时钟 */
    
    /* 初始化IWDG */
    hiwdg.Instance = IWDG;
    hiwdg.Init.Prescaler = IWDG_PRESCALER_32;  // 32分频
    hiwdg.Init.Reload = (IWDG_TIMEOUT * 40) / 1000;  // LSI约40kHz
    
    if(HAL_IWDG_Init(&hiwdg) != HAL_OK)
    {
        Error_Handler();
    }
}

/* 喂狗 */
void WATCHDOG_Refresh(void)
{
    HAL_IWDG_Refresh(&hiwdg);
}
/**
  * @file    pvd.c
  * @brief   PVD (Programmable Voltage Detector) implementation
  * @author  Your Name
  */

#include "pvd.h"
#include "main.h"

PWR_PVDTypeDef sConfigPVD;

/**
  * @brief  PVD初始化
  * @retval None
  */
void PVD_Init(void)
{
    /* 启用PWR时钟 */
    __HAL_RCC_PWR_CLK_ENABLE();
    
    /* 配置PVD */
    sConfigPVD.PVDLevel = PVD_LEVEL;
    sConfigPVD.Mode = PWR_PVD_MODE_IT_RISING_FALLING;
    HAL_PWR_ConfigPVD(&sConfigPVD);
    
    /* 启用PVD */
    HAL_PWR_EnablePVD();
    
    /* 配置和启用PVD中断 */
    HAL_NVIC_SetPriority(PVD_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(PVD_IRQn);
}

/**
  * @brief  PVD中断处理
  * @retval None
  */
void PVD_IRQHandler(void)
{
    /* 检查PVD中断标志 */
    if(__HAL_PWR_GET_FLAG(PWR_FLAG_PVDO) != RESET)
    {
        /* 电压低于阈值 - 掉电情况 */
        Power_off(); // 执行掉电处理
        
    }
    else
    {
				/* 电压恢复 - 上电情况 */
				// 执行软件复位，确保系统全新启动
				HAL_NVIC_SystemReset();
    }
		        /* 清除标志 */
        __HAL_PWR_CLEAR_FLAG(PWR_FLAG_PVDO);
}
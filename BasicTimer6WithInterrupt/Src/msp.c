/*
 * msp.c
 *
 *  Created on: Dec 13, 2018
 *      Author: yonur
 */

#include "main.h"

void HAL_MspInit(void)
{
	//Bu fonksiyon iÃ§erisinde islemciye ozgu dÃ¼ÅŸÃ¼k seviyeli ilklendirmeler
	//yapÄ±lÄ±r.
		//1. Arm cortex Mx iÅŸlemci priority grouping iÅŸlemleri yapÄ±lÄ±r.
		HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

		//2. Arm cortex Mx iÅŸlemcinin gerekli sistem exceptionslarÄ±
		//etkinliÅŸtirilir.
		SCB->SHCSR |= 0x7 << 16; //Usage fault, memory fault ve bus fault exception'larÄ± etkinleÅŸtirilir.

		//3. System exceptionslarÄ± iÃ§in priority konfigÃ¼re edilir.
		HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
		HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
		HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htimer) {

	//1. TIM6 için clock etkinleştirilir.
	__HAL_RCC_TIM6_CLK_ENABLE();

	//2. TIM6 için IRQ etkkinleştirilir.
	HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);

	//3. TIM6_DAC_IRQn için priority ayarlanır.
	HAL_NVIC_SetPriority(TIM6_DAC_IRQn, 15, 0);
}

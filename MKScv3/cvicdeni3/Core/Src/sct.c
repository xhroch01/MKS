/*
 * sct.c
 *
 *  Created on: Oct 11, 2023
 *      Author: xhroch01
 */
#include "main.h"
#include "sct.h"

void sct_init(void) {
	sct_led(0);
}

void sct_led(uint32_t value)
{
	for (uint8_t i = 0; i < 32; i++) {
		HAL_GPIO_WritePin(SCT_SDI_GPIO_Port, SCT_SDI_Pin, (value & 1));
		value >>= 1;
		HAL_GPIO_WritePin(SCT_SDI_GPIO_Port, SCT_CLK_Pin, 1);
		HAL_GPIO_WritePin(SCT_SDI_GPIO_Port, SCT_CLK_Pin, 0);
	}
	HAL_GPIO_WritePin(SCT_SDI_GPIO_Port, SCT_NLA_Pin, 1);
	HAL_GPIO_WritePin(SCT_SDI_GPIO_Port, SCT_NLA_Pin, 0);
}


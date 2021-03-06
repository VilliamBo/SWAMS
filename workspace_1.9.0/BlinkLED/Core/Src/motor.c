/*
 * 	Motordriver source file for SWAMS project
 *
 *	Used to control l298 dual H-bridge
 *
 *  Created on: Apr 20, 2022
 *  Author: David Vestergaard Kristensen
 *  AU student
 */

#include "motor.h"

void setLeftMotorDirection(int direction) /* direction 0 -> clockwise */
{
	if(direction == 0)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, SET);
	}
	else if(direction == 1)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);
	}
}

void setRightMotorDirection(int direction) /* direction 0 -> clockwise */
{
	if(direction == 0)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
	}
	else if(direction == 1)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
	}
}

// main motorDriver function
void setSpeed(int PWM){
	setDirection(PWM);
	setPWM(PWM);
}

void setDirection(int PWM){

	if(PWM >= 0)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);

		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);

	}
	else
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, SET);

		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);

	}
}

void setPWM(int PWM){

	PWM = ((abs(PWM)) * 1280 )/ 100;

	TIM2->CCR1 = PWM;
	TIM2->CCR2 = PWM;
}

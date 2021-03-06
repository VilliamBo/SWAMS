/*
 * controller.h
 *
 *  Created on: May 19, 2022
 *      Author: Villi
 */

#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

#include <stdint.h>

struct ControllerData
{
	//max gyro number is around 1500 (UNDERSØG) int16 is the lowest type size.
	//'_t' makes it 2'compliment to show negative numbers.
	int16_t setPoint; // position 1000/-1000
	int16_t currentValue; //Gyro position 1000/-1000
	float Kp;
	float Ki;
	int16_t iMax; // 100/-100
	int16_t iMin;
	int16_t IValue;
	int16_t out;

};

struct a
{
    int i;
    struct b
    {
        int j;
    };
};

void controlSpeed(struct ControllerData*);

void initControllerdata(struct ControllerData*);

#endif /* SRC_CONTROLLER_H_ */

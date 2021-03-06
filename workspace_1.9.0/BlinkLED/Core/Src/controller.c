/*
 * controller.c
 *
 *  Created on: May 19, 2022
 *      Author: Villi
 */

#include "controller.h"
#include <math.h>


void controlSpeed(struct ControllerData* ctrData){
	int16_t err = ctrData->setPoint - ctrData->currentValue;
	int16_t P =  ceil(ctrData->Kp*err);
	ctrData->IValue += err;
	if(ctrData->IValue > ctrData->iMax){
		ctrData->IValue = ctrData->iMax;
	}else if(ctrData->IValue < ctrData->iMin){
		ctrData->IValue = ctrData->iMin;
	}
	int16_t I =  ceil(ctrData->Ki* ctrData->IValue);
	ctrData->out = ceil((P + I)/10);
}

void initControllerdata(struct ControllerData* ctrData){
	ctrData->Ki = 0.01;
	ctrData->Kp = 0.3;
	ctrData->iMax = 1000;
	ctrData->iMin = -1000;
	ctrData->IValue = 0;
	ctrData->setPoint = 0;
	ctrData->currentValue = 0;
}

void increment(struct a* a){
	a->i = a->i + 1;
}




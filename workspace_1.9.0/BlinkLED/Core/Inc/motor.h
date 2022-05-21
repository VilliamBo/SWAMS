/*
 * 	Motordriver header file for SWAMS project
 *
 *	Used to control l298 dual H-bridge
 *
 *  Created on: Apr 20, 2022
 *  Author: David Vestergaard Kristensen
 *  AU student
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "main.h"
#include <stdlib.h>
#include <math.h>

void setLeftMotorDirection(int direction); /* direction 0 -> clockwise */
void setRightMotorDirection(int direction); /* direction 0 -> clockwise */

void setLeftMotorSpeed(int speed);
void setRightMotorSpeed(int speed);

// New structure
void setSpeed(int PWM); // main function
void setDirection(int PWM);
void setPWM(int PWM);

#endif /* INC_MOTOR_H_ */

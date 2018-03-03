/*
 * password.h
 *
 *  Created on: Feb 23, 2018
 *      Author: mostafa
 */

#ifndef HAL_PASSWORD_H_
#define HAL_PASSWORD_H_
#include"../MCAL/eeprom.h"

#include<avr/io.h>
#define MAX_PWD_L 10


#endif /* HAL_PASSWORD_H_ */
void PWD_save(char*ptr,unsigned char usr_add);
void PWD_get(char*ptr,unsigned char usr_add);

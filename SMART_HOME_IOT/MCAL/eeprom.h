/*
 * eeprom.h
 *
 *  Created on: Nov 30, 2017
 *      Author: Mostafa
 */

#ifndef MCAL_EEPROM_H_
#define MCAL_EEPROM_H_



#include<avr/io.h>




#endif /* MCAL_EEPROM_H_ */


void EEPROM_write(unsigned int address,unsigned char data);
unsigned char EEPROM_read(unsigned int adress);

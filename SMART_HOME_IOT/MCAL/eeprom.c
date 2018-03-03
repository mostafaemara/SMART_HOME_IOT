/*
 * eeprom.c
 *
 *  Created on: Nov 30, 2017
 *      Author: Mostafa
 */
#include"eeprom.h"

void EEPROM_write(unsigned int address,unsigned char data){


while(EECR&(1<<EEWE));


EEAR=address;

EEDR=data;


EECR|=(1<<EEMWE);
EECR|=(1<<EEWE);

}




unsigned char EEPROM_read(unsigned int address){



while(EECR&(1<<EEWE));



EEAR=address;



EECR|=(1<<EERE);

return EEDR;


}

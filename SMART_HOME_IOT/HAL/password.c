/*
 * password.c
 *
 *  Created on: Feb 23, 2018
 *      Author: mostafa
 */


#include"password.h"

void PWD_save(char*ptr,unsigned char usr_add){

for(unsigned char i=0;i<MAX_PWD_L;i++){

	EEPROM_write(usr_add++,ptr[i]);
}






}
void PWD_get(char*ptr,unsigned char usr_add){




	for(unsigned char i=0;i<MAX_PWD_L;i++){

		ptr[i]=EEPROM_read(usr_add++);
	}







}

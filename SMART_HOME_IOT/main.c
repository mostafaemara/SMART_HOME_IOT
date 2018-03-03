/*
 * main.c
 *
 *  Created on: Feb 28, 2018
 *      Author: mostafa
 */
#include<avr/io.h>
#include"HAL/wifi.h"
#include"HAL/lcd.h"
#include<util/delay.h>
int main(){

WIFI_init();

lcd_inti();

WIFI_echo_disable();
WIFI_tcp_send_byte('x');

while(1){

	WIFI_tcp_send_byte('x');

	}






}

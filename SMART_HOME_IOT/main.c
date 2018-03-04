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
	unsigned char ch[4]={0x1a,0x2b,0x3c,0x4d};
WIFI_init();

lcd_inti();
WIFI_echo_disable();




WIFI_tcp_connect("192.168.1.5","8080");



while(1){


}





}

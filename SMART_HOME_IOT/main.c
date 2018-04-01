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
#include"MCAL/timer.h"


#include"HAL/mqtt.h"








int main(){
unsigned char *bufz;


DDRD|=1<<PD7;
DDRA=0xff;
PORTA=0x00;
	lcd_inti();
unsigned char data[15]={0};
sei();
WIFI_init();
WIFI_echo_disable();


if(WIFI_ap_connect("SHAZAM","iamawesome321")==TRUE){


	lcd_goto(1,1);
	lcd_print("WIFI CONNECTED");
}else{

	lcd_goto(1,1);
	lcd_print("WIFI FAILD");




}
if(WIFI_tcp_connect("10.42.0.161","8080")==TRUE){

lcd_clear_screen();
	lcd_goto(1,1);
	lcd_print("TCP CONNECTED");
	WIFI_tcp_send_data(6,"HELLO\n");


}else{


	lcd_clear_screen();
		lcd_goto(1,1);
		lcd_print("TCP FAILD");

}

uart_append_tx_buffer("AT+CIPSTATUS\r\n",strlen("AT+CIPSTATUS\r\n"));

while(1){

	if(WIFI_status()==STATUS_TCP_CONNECTED){
		WIFI_wait();

		WIFI_tcp_send_data(3,"HI\n");

	}
	if(WIFI_status()==STATUS_TCP_CONNECTED){

WIFI_wait();

WIFI_tcp_send_data(6,"HELLO\n");

	}else if(WIFI_status()==STATUS_TCP_DISCONNECTED){
		WIFI_wait();

		if(WIFI_tcp_connect("10.42.0.161","8080")==TRUE){

		lcd_clear_screen();
			lcd_goto(1,1);
			lcd_print("TCP CONNECTED");



		}else{


			lcd_clear_screen();
				lcd_goto(1,1);
				lcd_print("TCP FAILD");

		}



	}else if(WIFI_status()==STATUS_WIFI_NOT_CONNECTED){
		WIFI_wait();
		lcd_clear_screen();
				lcd_goto(1,1);
				lcd_print("WIFI DISCONNECTED");








	}else if(WIFI_status()==STATUS_WIFI_CONNECTED_TCP_NOT){


		lcd_clear_screen();
					lcd_goto(1,1);
					lcd_print("WIFI CONNECTED");





}

if(wifi_rcv_data==DATA){

WIFI_get_data(data);

lcd_goto(2,2);
lcd_print(data);




}
}


}

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


volatile unsigned char timer_counter=0,timer_flag=0;

ISR(TIMER0_OVF_vect){


	if((timer_flag==0)){
if((timer_counter<200)){
timer_counter++;
}else{

	timer_counter=0;
	timer_flag=1;


}

}
}



int main(){
unsigned char* buffer;


DDRD|=1<<PD7;
DDRA=0xff;
PORTA=0xff;
	lcd_inti();

	timer0_init();

sei();
WIFI_init();
WIFI_echo_disable();

timer0_start(1024,5);

if(MQTT_connect()==1){


if(MQTT_sub()==TRUE){


	lcd_clear_screen();
	lcd_goto(2,6);


	lcd_print("ONLINE");
}else{



}
}else{


	lcd_clear_screen();
	lcd_goto(2,6);

			lcd_print("OFFLINE   ");
}







while(1){
	if(timer_flag==1){


	switch(WIFI_status()){

	case STATUS_TCP_DISCONNECTED:
		if(MQTT_connect()==1){


		if(MQTT_sub()==TRUE){



			lcd_goto(2,6);


			lcd_print("ONLINE   ");
		}else{



		}
		}else{


			lcd_goto(2,6);


					lcd_print("OFFLINE   ");

		}

break;
	case STATUS_WIFI_CONNECTED_TCP_NOT:

		if(MQTT_connect()==1){


			if(MQTT_sub()==TRUE){



				lcd_goto(2,6);


				lcd_print("ONLINE   ");
			}else{



			}
			}else{


				lcd_goto(2,6);


				lcd_print("OFFLINE   ");


			}


		break;
	case STATUS_WIFI_NOT_CONNECTED:

lcd_clear_screen();
lcd_goto(1,2);
lcd_print("WIFI DISCONNECT");
lcd_goto(2,6);

lcd_print("OFFLINE  ");


break;

	case STATUS_TCP_CONNECTED:
		lcd_clear_screen();
		lcd_goto(1,2);
		lcd_print("WIFI CONNECTED");
		lcd_goto(2,6);

		lcd_print("ONLINE  ");
break;

default:
	break;
	}
timer_flag=0;
}

if(wifi_rcv_data==DATA){


	MQTT_get_payload(&buffer);

if(strcmp(buffer,"LED ON")==0){


PORTA=0x00;

MQTT_pub();


}else if(strcmp(buffer,"LED OF")==0){
	PORTA =0xff;

	MQTT_pub();
}else{


}

wifi_rcv_data=0;
}



}
}

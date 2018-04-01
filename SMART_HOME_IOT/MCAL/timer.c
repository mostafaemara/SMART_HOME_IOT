/*
 * timer0.c
 *
 *  Created on: Oct 5, 2017
 *      Author: Mostafa
 */


#include"timer.h"



void timer0_rest(void){


	TCNT0=0;

}
void timer0_init(void){
	sei();


	TIMSK|=(1<<TOIE0);


}
void timer0_start(int prescale, int reg)
{

	if(prescale==1)  {TCCR0|=(1<<CS00);}
	else if(prescale==8){TCCR0|=(1<<CS01);}
	else if(prescale==64){TCCR0|=(1<<CS01)|(1<<CS00);}
	else if(prescale==256){TCCR0|=(1<<CS02);}
	else if (prescale==1024){TCCR0|=(1<<CS00)|(1<<CS02);}
	else{

		TCCR0=0;
	}

	TCNT0=reg;









}
void timer0_stop(void)
{

	TCCR0=0;



}
unsigned char timer0_get(void)
{

	return TCNT0;

}
void timer1_inti(void)
{
	sei();
TIMSK|=(1<<TOIE1);


}

void timer1_start(int prescale, int reg)
{

	if(prescale==1)  {TCCR1B|=(1<<CS10);}
	else if(prescale==8){TCCR1B|=(1<<CS11);}
	else if(prescale==64){TCCR1B|=(1<<CS11)|(1<<CS10);}
	else if(prescale==256){TCCR1B|=(1<<CS12);}
	else if (prescale==1024){TCCR1B|=(1<<CS10)|(1<<CS12);}
	else{

		TCCR1B=0;
	}

TCNT1=reg;
}

void timer1_stop(void){

	TCCR1B=0;


}
int timer1_get(void){


	return TCNT1;

}

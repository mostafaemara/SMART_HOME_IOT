/*
 * uart.c
 *
 *  Created on: Oct 24, 2017
 *      Author: Mostafa
 */

#include"uart.h"
#include<util/delay.h>
volatile queue uart_buffer;
volatile queue uart_tx_buffer;


ISR(USART_RXC_vect)
{


if((!queue_full(&uart_buffer))){

append_queue(UDR,&uart_buffer);

}
PORTD|=(1<<PD7);
if(UDR=='\r'){


    TCNT1=0xffff;


}else{

timer1_stop();
timer1_start(1,31000);
}

}


ISR(USART_UDRE_vect)
{
if((queue_size(&uart_tx_buffer)!=0)){

UDR=serve_queue(&uart_tx_buffer);

}else{




	UCSRB&=~(1<<UDRIE);


}



}

void uart_init(long baudrate){



	sei();
	UCSRB=(1<<RXEN)|(1<<TXEN)|(1<<RXCIE)|(1<<UDRIE);


			UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
			UBRRL=(unsigned char)(((F_CPU)/(16*baudrate))-1);

init_queue(&uart_tx_buffer);
init_queue(&uart_buffer);

}
void uart_send_byte(char byte){

	while((UCSRA&(1<<UDRE))==0);
UDR=byte;


}

int uart_recieve_byte(void){
	while((UCSRA&(1<<RXC))==0);
	return UDR;









}


void uart_append_tx_buffer(unsigned char*data,unsigned char size){
if(queue_size(&uart_tx_buffer)==0){
	unsigned char i=0;
for(i=0;i<(size);i++){




	if(!queue_full(&uart_tx_buffer)){



append_queue(data[i],&uart_tx_buffer);



	}



}


UCSRB|=(1<<UDRIE);









}
}

void uart_send_string(char* ptr){

	int i=0;

	while(ptr[i]!='\0'){



		uart_send_byte(ptr[i]);


		i++;



	}

	uart_send_byte(ptr[i]);



}

void uart_recieve_string(char*ptr){

	int i=0;
	ptr[i]=uart_recieve_byte();
	while(ptr[i]!='#'){
		i++;
		ptr[i]=uart_recieve_byte();






	}


ptr[i]='\0';





}



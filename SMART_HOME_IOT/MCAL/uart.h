/*
 * uart.h
 *
 *  Created on: Oct 24, 2017
 *      Author: Mostafa
 */

#define BAUD 115200
#define MYUBRR F_CPU/16/BAUD-1
#ifndef UART_H_
#define UART_H_
#include"../SERVICEL/queue.h"
#include<avr/io.h>
#include<avr/interrupt.h>
#include"../MCAL/timer.h"

void uart_init(long baudrate);
int uart_recieve_byte(void);
void uart_send_byte(char byte);
void uart_recieve_string(char* ptr);
void uart_send_string(char* ptr);
void uart_append_tx_buffer(unsigned char*data,unsigned char size);
extern volatile queue uart_buffer;
extern volatile queue uart_tx_buffer;
extern volatile unsigned char wifi_rsp;





#endif /* UART_H_ */

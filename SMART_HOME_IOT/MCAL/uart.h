/*
 * uart.h
 *
 *  Created on: Oct 24, 2017
 *      Author: Mostafa
 */

#ifndef UART_H_
#define UART_H_
#include"../SERVICEL/queue.h"
#include<avr/io.h>
#include<avr/interrupt.h>
void uart_init(long baudrate);
int uart_recieve_byte(void);
void uart_send_byte(char byte);
void uart_recieve_string(char* ptr);
void uart_send_string(char* ptr);

volatile queue uart_buffer;







#endif /* UART_H_ */

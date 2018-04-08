/*
 *
 * wifi.h
 *
 *  Created on: Feb 28, 2018
 *      Author: mostafa
 */

#ifndef HAL_WIFI_H_
#define WIFI_DELAY 10000
#define HAL_WIFI_H_
#include<string.h>
#include"../MCAL/uart.h"
#define WIFI_MAX_BUFFER 50
#define ST_MODE 1
#define AP_MODE 2
#define AP_ST_MODE 3
#define SSID "TheFlash"
#define PWD "Eeprom_flashrom@nvram225"
#include<util/delay.h>
#endif /* HAL_WIFI_H_ */
#define OK 'K'
#define ERROR 'R'
#define CONNECTED 'C'
#define ALREADY_CONNECTED 'A'
#define BUSY 'B'
#define NONE 'N'
#define SEND_OK 'S'
#define SEND_FAIL 'F'
#define CLOSED 'D'
#define DATA 'T'
#define OFF 0
#define WIFI_CONNECTED 'W'
#define WIFI_DISCONNECT 'X'
#define WIFI_GOT_IP 'I'
#define NO_IP 'O'
#define DNS_FAIL 'f'
#define READY_TO_RCV 'Y'
#define LINK_NOT_VALID 'V'
#define STATUS_TCP_CONNECTED '3'
#define STATUS_TCP_DISCONNECTED '4'
#define STATUS_WIFI_NOT_CONNECTED '5'
#define STATUS_WIFI_CONNECTED_TCP_NOT '2'

#define TRY_COUNT 1
#define WIFI_WIAT_COUNTER 450000000
typedef unsigned char bool;
typedef unsigned long counter;

void WIFI_init(void);
bool WIFI_rsp(void);
bool WIFI_status(void);
void WIFI_mode(char mode);
void WIFI_test(void);
bool WIFI_echo_disable(void);
unsigned char WIFI_ap_connect(unsigned char*ssid,unsigned char*pwd);
void WIFI_ap_disconnect(void);
bool WIFI_tcp_connect(char*ip,char *port);
void WIFI_tcp_send_data(unsigned char size,unsigned char *data);
void WIF_tcp_receive_data(unsigned char*data);
void WIFI_tcp_disconnect(void);
void WIFI_rst(void);
void WIFI_wait(void);
void WIFI_data_wait(void);
void WIFI_get_data(unsigned char *data_ptr);
extern volatile unsigned char wifi_rsp,wifi_rcv_data,wifi_data_size;
extern volatile queue data_buffer;


extern volatile unsigned char wifi_buffer[WIFI_MAX_BUFFER];
extern volatile unsigned char i_counter,j_counter;
extern volatile unsigned char temp_buffer[10];



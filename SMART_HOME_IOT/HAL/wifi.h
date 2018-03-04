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
typedef unsigned char bool;

void WIFI_init(void);
bool WIFI_rsp(void);
void WIFI_mode(char mode);
void WIFI_test(void);
void WIFI_echo_disable(void);
void WIFI_ap_connect(char*ssid,char*pwd);
void WIFI_ap_disconnect(void);
void WIFI_tcp_connect(char*ip,char *port);
void WIFI_tcp_send_data(unsigned char size,unsigned char *data);
<<<<<<< HEAD
void WIF_tcp_receive_data(unsigned char*data);
=======
>>>>>>> branch 'master' of https://github.com/mostafaemara/SMART_HOME_IOT.git
void WIFI_tcp_disconnect(void);
void WIFI_rst(void);

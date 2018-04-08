/*
 * mqtt.h
 *
 *  Created on: Mar 28, 2018
 *      Author: mostafa
 */

#ifndef HAL_MQTT_H_
#define USERNAME "yyhtphdb"
#define PASSWORD "bZ_l3M2CfgRe"
#define ID "MOSTAFA"
#define SERVER_ADD "m14.cloudmqtt.com"
#define SERVER_PORT "17582"
#define TOPIC "TEST"
#define KEEP_ALIVE 200
#define HAL_MQTT_H_


#include"wifi.h"
#endif /* HAL_MQTT_H_ */
#include<MQTTPacket.h>




unsigned char MQTT_sub(void);
unsigned char MQTT_connect(void);
int MQTT_get_payload(unsigned char **payload);

void MQTT_pub(void);

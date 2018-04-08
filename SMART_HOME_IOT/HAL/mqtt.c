/*
 * mqtt.c
 *
 *  Created on: Mar 28, 2018
 *      Author: mostafa
 */
#include"mqtt.h"




static int get_data(unsigned char*buf,int count){


	unsigned char i=0;
for(i=0;i<count;i++){

if(queue_size(&data_buffer)!=0){
	buf[i]=serve_queue(&data_buffer);

}




}

	return i;
}
unsigned char MQTT_connect(void)
{

	unsigned char buff[50]={0};
	int len=0;
 int s=0;
	unsigned char buffer_rcv[50]={0};
	MQTTString topicString = MQTTString_initializer;
	MQTTPacket_connectData data=MQTTPacket_connectData_initializer;
	data.username.cstring=USERNAME;
	data.password.cstring=PASSWORD;
	data.keepAliveInterval=KEEP_ALIVE;
	data.clientID.cstring=ID;
	topicString.cstring=TOPIC;

	WIFI_tcp_disconnect();
	wifi_rsp=0;
	_delay_ms(500);

	if(WIFI_tcp_connect(SERVER_ADD,SERVER_PORT)==TRUE){



	}else{

		return FALSE;

	}



	len=MQTTSerialize_connect(buff,50,&data);


	WIFI_tcp_send_data(len,buff);

     WIFI_data_wait();




      if(wifi_rcv_data==DATA){
      	wifi_rcv_data=0;
      if(MQTTPacket_read(buffer_rcv,50,get_data)==CONNACK){
    	  return TRUE;




    	  }else{




    		  return FALSE;
    	  }




      }else{




    	  return FALSE;
      }













return FALSE;



}


int MQTT_get_payload(unsigned char **payload){



	unsigned char buffer_rcv[100]={0};
	unsigned char dup;
				int qos;
				unsigned char retained;
				unsigned short msgid;
				int payloadlen_in;

	if(MQTTPacket_read(buffer_rcv,100,get_data)==PUBLISH){

		MQTTDeserialize_publish(&dup, &qos, &retained, &msgid, 0,
									payload, &payloadlen_in, buffer_rcv,100);


	}


















	return payloadlen_in;

}


unsigned char MQTT_sub(void){
	unsigned char buff[50]={0};
		int len=0;
	 int s=0;
		unsigned char buffer_rcv[50]={0};
		MQTTString topicString = MQTTString_initializer;


	topicString.cstring=TOPIC;

	  len = MQTTSerialize_subscribe(buff,50, 0, 1, 1, &topicString,&s);
	  WIFI_tcp_send_data(len,buff);

	  WIFI_data_wait();
	  if(wifi_rcv_data==DATA){
	      	wifi_rcv_data=0;
	  if(MQTTPacket_read(buffer_rcv,50,get_data)==SUBACK){

   return TRUE;


	  }else{


		  return FALSE;
	  }






	  }else{



		  return FALSE;

	  }


}
void MQTT_pub(void){

unsigned char buff[20]={0};
int len=0;




MQTTString topicString = MQTTString_initializer;

	topicString.cstring=TOPIC;


len = MQTTSerialize_publish(buff,40, 0, 0, 0, 0, topicString,(unsigned char*)"OK",2);


WIFI_tcp_send_data(len,buff);



}

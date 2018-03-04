/*
 * wifi.c
 *
 *  Created on: Feb 28, 2018
 *      Author: mostafa
 */

#include"wifi.h"


void WIFI_init(void){

uart_init(9600);




}

bool WIFI_rsp(void)
{

	char wifi_buffer[WIFI_MAX_BUFFER]={0};
	for(unsigned char i=0;i<(WIFI_MAX_BUFFER-1);i++){

			if((queue_size(&uart_buffer))!=0){

			wifi_buffer[i]=serve_queue(&uart_buffer);
			if((wifi_buffer[i]=='\n')&&(i>4)){
				wifi_buffer[i+1]='\0';
			break;

			}


			}


			}
if((strcmp(wifi_buffer,"\r\nERROR\r\n"))==0)
{

    return ERROR;

}
else if((strcmp(wifi_buffer,"\r\nOK\r\n"))==0)
{

	return OK;


}

else if((strcmp(wifi_buffer,"busy p...\r\n"))==0)
{
	return BUSY;
}
else if((strcmp(wifi_buffer,"CONNECT\r\n"))==0)
{


	return CONNECTED;
}
else if((strcmp(wifi_buffer,"ALREADY CONNECTED\r\n"))==0)
{

    return ALREADY_CONNECTED;
}else
{

	return NONE;
}







}
void WIFI_echo_disable(void){
	init_queue(&uart_buffer);
	uart_send_string("ATE0\r\n");
	_delay_ms(500);

}
void WIFI_mode(char mode){
	init_queue(&uart_buffer);
	char  buffer[16]={0};
	init_queue(&uart_buffer);
	sprintf(buffer,"AT+CWMODE=%d\r\n",mode);
		uart_send_string(buffer);
		_delay_ms(1000);


}
void WIFI_test(void){
	init_queue(&uart_buffer);
	uart_send_string("AT\r\n");
	_delay_ms(500);


}
void WIFI_ap_connect(char*ssid,char*pwd)
{
	char  buffer[50]={0};
	init_queue(&uart_buffer);
sprintf(buffer,"AT+CWJAP=\"%s\",\"%s\"\r\n",ssid,pwd);
	uart_send_string(buffer);
		_delay_ms(10000);


}
void WIFI_ap_disconnect(void){
	init_queue(&uart_buffer);
	uart_send_string("AT+CWQAP\r\n");
	_delay_ms(500);



}
void WIFI_tcp_connect(char*ip,char* port){
	char  buffer[50]={0};
		init_queue(&uart_buffer);
	sprintf(buffer,"AT+CIPSTART=\"TCP\",\"%s\",%s\r\n",ip,port);
		uart_send_string(buffer);
_delay_ms(5000);



}
void WIFI_tcp_send_data(unsigned char size,unsigned char *data)
{
<<<<<<< HEAD
char  buffer[50]={0};
init_queue(&uart_buffer); /*clear uart buffer*/
sprintf(buffer,"AT+CIPSEND=%d\r\n",size);
=======
char  buffer[16]={0};
init_queue(&uart_buffer); /*clear uart buffer*/
sprintf(buffer,"AT+CIPSEND=%d",size);
uart_send_string(buffer);
uart_send_string(data);
>>>>>>> branch 'master' of https://github.com/mostafaemara/SMART_HOME_IOT.git

<<<<<<< HEAD
uart_send_string(buffer);
_delay_ms(1000);
for(unsigned char i=0;i<(size);i++)
{

uart_send_byte(data[i]);

}

 _delay_ms(5000);
=======
 _delay_ms(12000);
>>>>>>> branch 'master' of https://github.com/mostafaemara/SMART_HOME_IOT.git



}



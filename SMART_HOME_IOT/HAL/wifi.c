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

bool WIFI_RSP(void)
{
for(unsigned i=0;i<(WIFI_MAX_BUFFER-1);i++){
wifi_buffer[i]=0;
if((queue_size(&uart_buffer))!=0){

wifi_buffer[i]=serve_queue(&uart_buffer);


}


}

if((strcmp(wifi_buffer,"ERROR"))==0){

return 'R';

}else if((strcmp(wifi_buffer,"OK"))==0){



	return OK;


}else{
	return 'n';
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
	char  buffer[16]={0};
	init_queue(&uart_buffer);
sprintf(buffer,"AT+CWJAP=\"%s\",\"%s\"\r\n",ssid,pwd);
	uart_send_string(buffer);
		_delay_ms(12000);


}
void WIFI_ap_disconnect(void){
	init_queue(&uart_buffer);
	uart_send_string("AT+CWQAP\r\n");
	_delay_ms(500);



}
void WIFI_tcp_connect(char*ip,char* port){
	char  buffer[16]={0};
		init_queue(&uart_buffer);
	sprintf(buffer,"AT+CIPSTART=\"TCP\",\"%s\",%s\r\n",ip,port);
		uart_send_string(buffer);
			_delay_ms(1000);



}
void WIFI_tcp_send_data(unsigned char size,unsigned char *data)
{
char  buffer[16]={0};
init_queue(&uart_buffer); /*clear uart buffer*/
sprintf(buffer,"AT+CIPSEND=%d",size);
uart_send_string(buffer);
uart_send_string(data);

 _delay_ms(12000);



}



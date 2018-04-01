/*
 * wifi.c
 *
 *  Created on: Feb 28, 2018
 *      Author: mostafa
 */

#include"wifi.h"
volatile queue data_buffer;

volatile unsigned char wifi_rsp=0,wifi_rcv_data=0,wifi_data_size=0;
volatile unsigned char wifi_buffer[WIFI_MAX_BUFFER]={0};
volatile unsigned char i_counter=0,j_counter=0;
volatile unsigned char temp_buffer[10]={0};


ISR(TIMER1_OVF_vect){
	PORTD&=~(1<<PD7);

	timer1_stop();



	for( i_counter=0;i_counter<(WIFI_MAX_BUFFER-1);i_counter++){
		wifi_buffer[i_counter]=0;

			if((queue_size(&uart_buffer))!=0){

			wifi_buffer[i_counter]=serve_queue(&uart_buffer);

			}
			else{


				break;
			}




			}



	 if((strcmp(wifi_buffer,"OK\r\n"))==0)
{

	wifi_rsp=OK;



}
else if((strcmp(wifi_buffer,"SEND OK\r\n"))==0)
{

	wifi_rsp=SEND_OK;


}
else if((strcmp(wifi_buffer,"> "))==0)
{

	wifi_rsp=READY_TO_RCV;


}
else if((strcmp(wifi_buffer,"busy s...\r\n"))==0)
{
	wifi_rsp=0;

}
else if((strcmp(wifi_buffer,"busy p...\r\n"))==0)
{
	wifi_rsp=0;

}



else if((strcmp(wifi_buffer,"CONNECT\r\n"))==0)
{


	wifi_rsp=CONNECTED;

}
else if((strcmp(wifi_buffer,"CLOSED\r\n"))==0)
{


	wifi_rsp=CLOSED;

}
else if((strcmp(wifi_buffer,"link is not valid\r\n"))==0)
{


	wifi_rsp=LINK_NOT_VALID;

}

else if((strcmp(wifi_buffer,"ALREADY CONNECTED\r\n"))==0)
{

	wifi_rsp=ALREADY_CONNECTED;

}
else if((strcmp(wifi_buffer,"ERROR\r\n"))==0)
{

wifi_rsp=ERROR;

}
else if((strcmp(wifi_buffer,"WIFI CONNECTED\r\n"))==0)
{

wifi_rsp=WIFI_CONNECTED;

}
else if((strcmp(wifi_buffer,"WIFI DISCONNECT\r\n"))==0)
{

wifi_rsp=WIFI_DISCONNECT;

}
else if((strcmp(wifi_buffer,"WIFI GOT IP\r\n"))==0)
{

wifi_rsp=WIFI_GOT_IP;

}
else if((strcmp(wifi_buffer,"\r\n"))==0)
{

wifi_rsp=0;

}
else if((strcmp(wifi_buffer,"no ip\r\n"))==0)
{

wifi_rsp=NO_IP;

}
else if((strcmp(wifi_buffer,"STATUS:3\r\n"))==0)
{

wifi_rsp=STATUS_TCP_CONNECTED;

}
else if((strcmp(wifi_buffer,"STATUS:4\r\n"))==0)
{

wifi_rsp=STATUS_TCP_DISCONNECTED;

}
else if((strcmp(wifi_buffer,"STATUS:5\r\n"))==0)
{

wifi_rsp=STATUS_WIFI_NOT_CONNECTED;

}
else if((strcmp(wifi_buffer,"STATUS:2\r\n"))==0)
{

wifi_rsp=STATUS_WIFI_CONNECTED_TCP_NOT;

}
else if(((wifi_buffer[0]=='+')&&(wifi_buffer[1]=='I'))){


for(i_counter=0;i_counter<10;i_counter++){

	temp_buffer[i_counter]=0;


}
init_queue(&data_buffer);

	for(i_counter=5;i_counter<17;i_counter++){

if(wifi_buffer[i_counter]!=':'){
temp_buffer[i_counter-5]=wifi_buffer[i_counter];

}else{
	i_counter++;


	break;
}


	}


	wifi_data_size=atoi(temp_buffer);
	if(wifi_data_size==0){




	}else{


	}

for(j_counter=0;j_counter<wifi_data_size;j_counter++){


if(!queue_full(&data_buffer)){

append_queue(wifi_buffer[i_counter+j_counter],&data_buffer);

}

}

wifi_rcv_data=DATA;



}
else
{

	wifi_rsp=0;

}




 init_queue(&uart_buffer);


}


void WIFI_init(void){
init_queue(&uart_buffer);
uart_init(2400);
timer1_inti();




}


bool WIFI_echo_disable(void){

	init_queue(&uart_buffer);


		wifi_rsp=0;
		uart_append_tx_buffer("ATE0\r\n",strlen("ATE0\r\n"));
		WIFI_wait();
		if(wifi_rsp==OK){

      return TRUE;

		}else{
			return FALSE;


		}
 }









void WIFI_mode(char mode){


	wifi_rsp=0;
	char  buffer[16]={0};
	init_queue(&uart_buffer);
	sprintf(buffer,"AT+CWMODE=%d\r\n",mode);
		uart_append_tx_buffer(buffer,strlen(buffer));
		WIFI_wait();
		if(wifi_rsp==OK){


				}else{

					wifi_rsp=0;
				}


	 wifi_rsp=0;
}
void WIFI_test(void){
for(unsigned char i=0;i<TRY_COUNT;i++)
{

	init_queue(&uart_buffer);
	wifi_rsp=0;

	uart_send_string("AT\r\n");
	WIFI_wait();
	if(wifi_rsp==OK){
break;

	}
	else{


	}
	}
	wifi_rsp=0;
}
bool WIFI_ap_connect(char*ssid,char*pwd)
{
wifi_rsp=0;
char  buffer[50]={0};
init_queue(&uart_buffer);
sprintf(buffer,"AT+CWJAP=\"%s\",\"%s\"\r\n",ssid,pwd);
uart_append_tx_buffer(buffer,strlen(buffer));
WIFI_wait();


   if (wifi_rsp==WIFI_CONNECTED){

    WIFI_wait();
    if(wifi_rsp==WIFI_GOT_IP){

    	WIFI_wait();
    	if(wifi_rsp==OK){

    		return TRUE;

    	}else{
    		return FALSE;


    	}


    }else{
    	return FALSE;


    }

   }else if(wifi_rsp==WIFI_DISCONNECT){
	   WIFI_wait();
	     if (wifi_rsp==WIFI_CONNECTED){

	      WIFI_wait();
	      if(wifi_rsp==WIFI_GOT_IP){

	      	WIFI_wait();
	      	if(wifi_rsp==OK){

	      		return TRUE;

	      	}else{
	      		return FALSE;


	      	}


	      }else{
	      	return FALSE;


	      }

	     }





   }else{

	   return FALSE;

   }




}
void WIFI_ap_disconnect(void){
	wifi_rsp=0;
	init_queue(&uart_buffer);
	uart_send_string("AT+CWQAP\r\n");
	WIFI_wait();
	wifi_rsp=0;



}
bool WIFI_tcp_connect(char*ip,char* port){


	char  buffer[50]={0};
	init_queue(&uart_buffer);
	sprintf(buffer,"AT+CIPSTART=\"TCP\",\"%s\",%s\r\n",ip,port);
	uart_append_tx_buffer(buffer,strlen(buffer));
	WIFI_wait();
		switch(wifi_rsp){
		case(CONNECTED):
	      WIFI_wait();
		return TRUE;
break;
		case(ALREADY_CONNECTED):
			WIFI_wait();
		return TRUE;
		break;
		case(ERROR):
        WIFI_wait();
		return FALSE;
		break;
		case(NO_IP):
		WIFI_wait();
		return FALSE;
		break;
		default:
			return FALSE;
				break;

		}


	wifi_rsp=0;



}

void WIFI_tcp_disconnect(void){
	for(unsigned char i=0;i<TRY_COUNT;i++){
	wifi_rsp=0;
	uart_append_tx_buffer("AT+CIPCLOSE\r\n",strlen("AT+CIPCLOSE\r\n"));
	WIFI_wait();

if(wifi_rsp==CLOSED){

	break;
}else{



}


	}
	wifi_rsp=0;

}
void WIFI_tcp_send_data(unsigned char size,unsigned char *data)
{
	wifi_rsp=0;

     char buffer[50]={0};
init_queue(&uart_buffer); /*clear uart buffer*/
sprintf(buffer,"AT+CIPSEND=%d\r\n",size);

uart_append_tx_buffer(buffer,strlen(buffer));
WIFI_wait();
if(wifi_rsp==OK)
{


	WIFI_wait();

		if(wifi_rsp==READY_TO_RCV){


	uart_append_tx_buffer(data,size);

	WIFI_wait();
	 if(wifi_rsp==SEND_OK){








			}



		}


}else if(wifi_rsp==LINK_NOT_VALID){


	WIFI_wait();

if(wifi_rsp==ERROR){


}


}








wifi_rsp=0;





}
void WIFI_wait(void){
	wifi_rsp=0;
	for(counter i=0;i<WIFI_WIAT_COUNTER;i++){
			if(wifi_rsp!=0){


				break;
			}


			}



}


void WIFI_data_wait(void){




	for(counter i=0;i<WIFI_WIAT_COUNTER;i++){
				if(wifi_rcv_data==DATA){


					break;
				}


				}





}




void WIFI_get_data(unsigned char *data_ptr){


for(unsigned char j=0;j<100;j++){


data_ptr[j]=0;

}

	for(unsigned char i=0;i<wifi_data_size;i++){

if(queue_size(&data_buffer)!=0){


data_ptr[i]=serve_queue(&data_buffer);

}

	}


wifi_rcv_data=0;
wifi_data_size=0;







}

bool WIFI_status(void){
	uart_append_tx_buffer("AT+CIPSTATUS\r\n",strlen("AT+CIPSTATUS\r\n"));

WIFI_wait();
if(wifi_rsp==OK){
	WIFI_wait();
return wifi_rsp;
}

















}


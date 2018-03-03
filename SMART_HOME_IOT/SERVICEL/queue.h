/*
 * queue.h
 *
 *  Created on: Dec 21, 2017
 *      Author: mostafa
 */



#define MAXQUEUE 50
#define TRUE 1
#define FALSE 0
typedef  char qelement;

typedef struct  {
	qelement qe[MAXQUEUE];
    unsigned char front;
    char rear;
    unsigned char size;




}queue;


void init_queue(queue*qptr);
void append_queue(qelement e,queue*qptr);
qelement serve_queue(queue*ptr);
unsigned char queue_full(queue*qptr);
unsigned char queue_size(queue*qptr);

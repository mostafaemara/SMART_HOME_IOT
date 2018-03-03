

#include"queue.h"




void init_queue(queue*qptr){


	qptr->front=0;
	qptr->rear=(-1);
	qptr->size=0;






}
void append_queue(qelement e,queue*qptr){




	if((qptr->rear==(MAXQUEUE-1))){

		qptr->rear=0;
	}
	else{
		qptr->rear++;

	}
	qptr->qe[qptr->rear]=e;
	qptr->size++;




}
qelement serve_queue(queue*qptr){
qelement e=0;

e=qptr->qe[qptr->front];

if((qptr->front==(MAXQUEUE-1))){

		qptr->front=0;
	}
	else{
		qptr->front++;

	}

qptr->size--;

return e;


}
unsigned char queue_full(queue*qptr){

if(qptr->size==(MAXQUEUE)){

	return TRUE;
}

	else {


		return FALSE;

	}




}

unsigned char queue_size(queue*qptr){


return qptr->size;



}










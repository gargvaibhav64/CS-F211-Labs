#include <stdio.h>
#include "multiQ.h"
#include <stdlib.h>

MultiQ createMQ(int num) // creates a list of num Queues, each of which is empty.
{
	MultiQ m;
	m = (Queue) malloc(sizeof(Que) * num);

	return m;
}


MultiQ addMQ(MultiQ mq, Task t) // adds t to the Queue corresponding to priority p in mq. Task includes a TaskID tid and a priority p.
{
	int element = t.id;
	Priority pri = t.pri;
	Element new = (Element)malloc(sizeof(Ele));

	new->ele = element;
	new->next = NULL;

	if(isEmptyQ(&mq[pri.pri_no-1]) == TRUE)
	{
		Queue q = newQ();
		mq[pri.pri_no-1] = *q;
	}

	Queue q = addQ(&mq[pri.pri_no-1], new);
	mq[pri.pri_no-1] = *q;

	return mq;
}


Task nextMQ(MultiQ mq) // returns the front of the non-empty Queue in mq with the highest priority.
{
	Element temp; Task t; Priority p;
	for(int i = 0 ; i < MAX ; i++){
		if(isEmptyQ(&mq[i]) == FALSE){
			temp = (&mq[i])->first;
			t.id = temp->ele;
			p.pri_no = i;
			t.pri = p;
			return t;
		}
	}

	return t;
}

MultiQ delNextMQ(MultiQ mq) // deletes the front of the non-empty Queue in mq with the highest priority; returns the modified MultiQ
{
	for(int i = 0 ; i < MAX ; i++){
		if(isEmptyQ(&mq[i]) == FALSE){
			mq[i] = *(delQ(&mq[i]));
		}
	}
	return mq;
}

Boolean isEmptyMQ(MultiQ mq) // tests whether all the Queues in mq are empty
{
	for(int i = 0 ; i < MAX; i++){
		if(isEmptyQ(&mq[i]) == FALSE){
			return FALSE;
		}
	}

	return TRUE;
}

int sizeMQ(MultiQ mq) // returns the total number of items in the MultiQ
{
	int count = 0;
	for(int i = 0 ; i < MAX ; i++){
		count += lengthQ(&mq[i]);
	}

	return count;

}

int sizeMQbyPriority(MultiQ mq, Priority p) //returns the number of items in mq with the priority p.
{
	int count = 0;

	count += lengthQ(&mq[p.pri_no - 1]);

	return count;

}

Queue getQueueFromMQ(MultiQ mq, Priority p) //returns the Queue with priority p.
{
	return &mq[p.pri_no];
}


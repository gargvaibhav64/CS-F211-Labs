#include <stdio.h>
#include "que.h"
#define MAX 10

typedef struct{
	int pri_no;
}Priority;

typedef struct{
	int id;
	Priority pri;
}Task;

typedef Que * MultiQ;

MultiQ createMQ(int num); // creates a list of num Queues, each of which is empty.


MultiQ addMQ(MultiQ mq, Task t); // adds t to the Queue corresponding to priority p in mq. Task includes a TaskID tid and a priority p.


Task nextMQ(MultiQ mq); // returns the front of the non-empty Queue in mq with the highest priority.


MultiQ delNextMQ(MultiQ mq); // deletes the front of the non-empty Queue in mq with the highest priority; returns the modified MultiQ

Boolean isEmptyMQ(MultiQ mq); // tests whether all the Queues in mq are empty

int sizeMQ(MultiQ mq); // returns the total number of items in the MultiQ

int sizeMQbyPriority(MultiQ mq, Priority p); //returns the number of items in mq with the priority p.

Queue getQueueFromMQ(MultiQ mq, Priority p); //returns the Queue with priority p.
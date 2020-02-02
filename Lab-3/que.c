#include <stdio.h>
#include <stdlib.h>
#include "que.h"

Queue newQ() // returns an empty Queue
{
	Queue q = (Queue) malloc(sizeof(Que));
	q->count = 0;
	q->first = NULL;
	q->last = NULL;
	return q;
}

Boolean isEmptyQ(Queue q) // tests whether q is empty
{
	if(q->count == 0){
		return TRUE;
	}

	return FALSE;

}

Queue delQ(Queue q) // deletes the element from the front of the Queue; returns the modified Queue
{
	Element temp;
	temp = q->first;

	q->first = temp->next;
	q->count--;

}

Element front(Queue q) // returns the element from the front of the Queue;
{
	Element temp = q->first;
	return temp;
}


Queue addQ(Queue q , Element e) // adds e to the rear of the Queue; returns the modified Queue
{
	/*node * new = (node * new)malloc(sizeof(node * new));
	new.ele = e;
	new.next = NULL;*/

	if(isEmptyQ(q) == TRUE)
	{
		q->first = e;
		q->last = e;	
	}
	else
	{	
		Element temp = q->last;
		temp -> next = e;		
		q->last = e;
	}

	q->count++;
	return q;
}
	
int lengthQ(Queue q){
	return q->count;
}
	

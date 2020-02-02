#include "stack.h"
#include <stdlib.h>

void push ( struct linkedList * head, int ele){
	
	insertFirst(head, ele);

}

void pop (struct linkedList * head){
	
	struct node * temp = deleteFirst(head);

	free(temp);

}

void printStack(struct linkedList * head){
	
	printlist(head);

}

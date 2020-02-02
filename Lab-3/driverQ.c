#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(){
	FILE * fileptr;

	fileptr = fopen("queueInput.txt", "r");

	Queue q = newQ();
	
	while(!feof(fileptr))
	{
		int temp;
		fscanf(fileptr, "%d ", &temp);

		node new = (node new)malloc(sizeof(node new));
		new.ele = e;
		new.next = NULL;

		Queue addQ(q , new)

	}
	

}





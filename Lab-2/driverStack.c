#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(){
	FILE * fileptr;

	fileptr = fopen("stackInput.txt", "r");

	struct linkedList * head = (struct linkedList *) malloc (sizeof(struct linkedList));

	while(!feof(fileptr))
	{
		int temp;
		fscanf(fileptr, "%d ", &temp);

		push(head, temp);

	}
	
	int count = head->count;

	while(count--){
		printStack(head);
		pop(head);
		
	}

}





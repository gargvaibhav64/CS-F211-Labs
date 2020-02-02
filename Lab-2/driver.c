#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main(int argc, char *argv[])
{
	FILE * fileptr;

	if(argc > 1){
		fileptr = fopen(argv[1], "r");
	}
	
	if(fileptr == NULL){
		printf("Could not open file");
		exit(0);
	}

	struct linkedList * head = (struct linkedList *) malloc (sizeof(struct linkedList));

	while(!feof(fileptr))
	{
		int temp;
		fscanf(fileptr, "%d ", &temp);

		insertFirst(head, temp);

	}

	fclose(fileptr);

	printlist(head);
	
	struct node* temp = deleteFirst(head);

	printlist(head);

}




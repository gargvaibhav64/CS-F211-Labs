#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cycle.h"
#include "func.h"

extern int space;

LinkedList * createList(int n){
	LinkedList * newLL = (LinkedList *)myalloc(sizeof(LinkedList));

	if(newLL == NULL){
		printf("LL couldn't be created");
	}

	newLL-> size = 0;
	newLL-> first = NULL;
	
	Node * temp;

	for(int i = 0 ;  i < n; i++)
	{
		Node * new = (Node *)myalloc(sizeof(Node));

		if(new==NULL){
			printf("Couldn't allocate memory");
			break;
		}

		new->ele = rand() % 15000;

		new->next = NULL;

//		temp = newLL->first;

		if(newLL->size == 0){
			//printf("About to create Node 1\n");
			newLL-> first = new;
			newLL-> size++;
			temp = newLL->first;
		}
		else{
			temp->next = new;
			temp = temp->next;
//			printf("Inserting Node %d %u\n", newLL-> size, &temp);
//			printList(newLL);
			
			//temp->next = new;
				
			newLL-> size++;
		}
	}

	//printf("Created all nodes\n");

	return newLL;
}

LinkedList * createCycle(LinkedList * ls){
	if(ls->size < 2 || ls == NULL){
		printf("Empty LinkedList or LinkedList with 1 element received!!!");
		return NULL;
	}
	
	int chance = rand() % 2;
	printf("Chance : %d\n", chance);

	if(chance == 0){

		Node * temp, * point;
		temp = ls->first;

		int pos = rand() % (ls->size - 1);

		while(temp->next != NULL){
			temp = temp->next;
			if(--pos == 0){
				point = temp;
				//printf("Cycle created\n");
			}
		}	

		temp->next = point;
	}
	else{
		//printf("No cyclic Linked List created\n");
	//	printList(ls);
	}

	return ls;
}

void printList(LinkedList * temp){
	Node * first = temp->first;
	if(first == NULL){
		printf("Empty List");
		return;
	}
	int count = 0;
	printf("[ ");
	while(first !=NULL && count < 20){ //To prevent infinite printing in case of cycles
		printf("%d\t%d\n", first->ele, count);
		first = first->next;
		count++;
	}
}

void * myalloc(size_t size){
	void * temp = malloc(size);
	//printf("Size: %d\n", size);
	
	space+=size;
	//printf("Space allocated in this loop: %d\n", space);
	return temp;
}

void myfree(void * ptr, int size){
	free(ptr);
	space-=size;
	//printf("Space: %d\n", space);

}
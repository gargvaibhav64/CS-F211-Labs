#include "linkedlist.h"
#include <stdlib.h>

void insertFirst ( struct linkedList * head, int ele){
	
	struct node *link = (struct node*) malloc (sizeof(struct node));

	link->element = ele;
	
	link->next = head->first;

	head->first = link;
	head->count++;

}

struct node * deleteFirst(struct linkedList * head){
	
	struct node * temp = head->first;
	
	head->first = temp->next;

	head->count --;

	return temp;

}

void printlist(struct linkedList * head){

	struct node *ptr = head->first;
	printf("\n[ ");

	while(ptr!= NULL){
		printf("%d, ", ptr->element);

		ptr = ptr->next;

	}

	printf(" ]");
}

int search (struct linkedList * head, int ele){

	struct node *ptr = head->first;

	while(ptr!= NULL){
		if(ptr->element == ele){
			printf("Element found");
			return 1;	
		}

		ptr = ptr->next;

	}

	return 0;

}

struct node * delete ( struct linkedList * head, int ele){

	int check = search(head, ele);
	struct node * temp;

	if(check == 0){
		printf("Element not found");

	}
	else{
		struct node *ptr = head->first;
		
		if(ptr->element == ele){
			temp = deleteFirst(head);
			return temp;
		}

		while(ptr->next != NULL){
			if((ptr->next)->element == ele){
				temp = ptr->next;
				ptr->next  = temp->next;
				head->count --;
			}

			ptr = ptr->next;

		}
	}
		
}

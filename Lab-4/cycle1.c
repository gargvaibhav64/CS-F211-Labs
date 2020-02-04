#include <stdio.h>
#include <stdlib.h>
#include "cycle.h"

//Uses the Hare-Tortoise algorithm to detect cycles
// Returns 1 if a cycle is present and 0 if not present

int testCyclic(LinkedList * ls){
	if(ls->size < 2){
		return 0;	
	}

	else if(ls-> size == 2){
		Node * first = ls->first;
		Node * second = first->next;
		if(second->next != first){
			return 0;
		}
	}
	else{
		Node * hare, *tort;
		tort = ls->first;
		hare = ls->first;

		while(hare!=tort || hare!=NULL){
			if(tort->next == NULL || (hare->next == NULL) || (hare -> next) -> next == NULL){
				return 0;	
			}
			tort = tort -> next;
			hare = (hare -> next) -> next;
			
			if(hare == tort && hare!=NULL && tort!=NULL){
				return 1; //Cycle found
			}
		}

	}

	printf("Fallback");
	return 0;

}

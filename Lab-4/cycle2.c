#include <stdio.h>
#include <stdlib.h>
#include "cycle.h"

//Uses the Link Reversal algorithm to detect cycles
// Returns 1 if a cycle is present and 0 if not present

LinkedList * reverseList(LinkedList * ls){
    Node * prev = ls->first;
    Node * curr = prev->next;
    Node * next = curr->next;

    prev->next = NULL;
    
    while (next != NULL)
    {		
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
		ls->first = prev;   
    }

	curr->next = prev;
	ls->first = curr;

    return ls;    
}

int testCyclic(LinkedList * ls){
    int flag  = 0;
	if(ls->size < 2){
		return 0;	
	}

	else if(ls-> size == 2){
		Node * first = ls->first;
		Node * second = first->next;
		if(second->next != first){
			return 0;
		}
        else
        {
            return 1;
        }
        
	}
	else{
        Node * temp = ls->first;
        ls = reverseList(ls);

        if(temp == ls->first){
            flag = 1;
        }

        ls = reverseList(ls);

    }
    if(flag == 1){
        return 1;
    }
	return 0;

}

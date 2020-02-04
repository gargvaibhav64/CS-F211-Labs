#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>
#include "cycle.h"
#include "func.h"

int space = 0;

int main(){
    struct timeval t1, t2;
	double elapsedTime;
	srand(time(NULL));

	LinkedList * ll;
    int size = 0;
    int s1 = 1;
    while(size++ <= 6){
        s1*=10;
        printf("Creating linked list of size %.d\n", s1);

        ll = createList(s1);
        printf("Linked list successfully created...\n\n");
        printf("Trying to create a cycle on random allotment\nChance : 0 -> Cycle will be created\nChance : 1 -> Cycle will not be created\n\n");
        ll = createCycle(ll);

        printf("\nNow checking for a cycle using testCyclic function\n");

        gettimeofday(&t1, NULL);
        int flag = testCyclic(ll);
        gettimeofday(&t2, NULL);
        

        if(flag==1){
            printf("Cycle detected\n");
        }
        else{
            printf("Cycle not detected\n");
        }

        elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
        printf("Total time taken for testCyclic %f ms.\n", elapsedTime);

        printf("Total heap space utilized: %d\n\n\n", space);
    }
	return 0;
}


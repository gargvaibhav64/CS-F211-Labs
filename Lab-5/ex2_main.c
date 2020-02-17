#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"
#include "ex2.h"
#include "struct.h"
#include <time.h>
#include <sys/time.h>

int si;

int main(){
    struct timeval t1, t2;
	double elapsedTime;
    FILE * fptr;

    struct card * new = (struct card *)malloc(sizeof(struct card)*size_Struct);

    struct card * a = new;

    int i = 0;

    int fname = 10;

    //printf("%lu\n", sizeof(struct card));
    for(int j = 0; j < 5 ; j++){

        char * temp = malloc(sizeof(char)*100);
        sprintf(temp, "%d", fname);
        fptr = fopen(temp,"r");

        if(fptr == NULL){
            printf("Error opening file\n");
        }

        gettimeofday(&t1, NULL);
        new = create_arr(new,fptr);
        gettimeofday(&t2, NULL);

        elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
        printf("Total time taken for inserting %d cards is %f ms.\n", fname, elapsedTime);

        i = 0;
        int di;

        a = new;
        

        gettimeofday(&t1, NULL);
        a = insertionSort(a, size_Struct-1);
        gettimeofday(&t2, NULL);
        printf("Stack size is %d\n", (int)&di - si);

        elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
        printf("Total time taken for sorting %d cards is %f ms.\n\n", fname, elapsedTime);

        fname*=10;
        
        int count = 0;

        // Uncomment below to check array contentss
        // while(count < size_Struct-1){
        //     printf("%lld, %s, %s, %s, %s\n", a->num, a->bankcode, a->exp_Date, a->first_name, a->last_name); 
        //     a++;
        //     count++;
        // }

        a=new;

    }

    //printf("%d",size_Struct);
    return 0;
}
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "struct.h"
#include "ex1.h"

int main(){
    struct timeval t1, t2;
	double elapsedTime;
    FILE * fptr;

    struct card * new = (struct card *)malloc(sizeof(struct card)*size_Struct);

    int fname = 10;

    for(int j = 0; j < 7 ; j++){

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
        printf("Total time taken for %d cards is %f ms.\n", fname, elapsedTime);

        fname*=10;

    }
    return 0;
}
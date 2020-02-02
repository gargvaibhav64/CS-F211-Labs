#include "multiQ.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

MultiQ mq;

MultiQ loadData(FILE *f);
MultiQ testDel(int num);

int main(int argc, char * argv[]){
    struct timeval t1, t2;
    double elapsedTime;

    FILE * fileptr;
    if(argc == 2){

        fileptr = fopen(argv[1], "r");
        mq = loadData(fileptr);

        gettimeofday(&t1, NULL);
        mq = testDel(MAX);
        gettimeofday(&t2, NULL);

        elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
        printf("Total time is %f ms.\n", elapsedTime);
    
    }

    return 0;
}

MultiQ loadData(FILE *fptr){

    if(fptr == NULL){
        printf("Error opening file\n");
        exit(0);
    }

    mq = createMQ(MAX);

    if(mq==NULL){
        printf("Error");
    }

	while(!feof(fptr))
	{
		int id, pri;
		fscanf(fptr, "%d,%d", &id, &pri);

        Priority p;
        p.pri_no = pri;
        Task t;
        t.id = id;
        t.pri = p;
        
        mq = addMQ(mq,t);
	}

    return mq;
}

MultiQ testDel(int num){
    while (num--)
    {
        mq = delNextMQ(mq);
    }

    return mq;
}
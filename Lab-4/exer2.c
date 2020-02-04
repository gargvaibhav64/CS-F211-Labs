#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int space;

void * myalloc(size_t size);
void myfree(void * ptr, int size);

int main(){
	space = 0;
	int *a;
	for(int i = 0 ;  i < 1; i++)
	{
		srand(time(NULL));
		int r = rand() % 15000;
		r += 10000;
		a = (int *)myalloc(sizeof(int)*r);
	//	printf("%d\n",r);

		printf("First: %u\n", &a[0]);
		printf("Last: %u\n", &a[r-1]);
		
	//	printf("Heap allocated in this loop: %d\n", space);

		myfree(a,sizeof(int)*r);

		if(a==NULL){
			break;

		}	
	}

	return 0;
	
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


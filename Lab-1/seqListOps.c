/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

void printlist(SeqList sl);

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int inputJobs (JobList list)
{
 int i; int size;

 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  getchar();
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&list[i].pri);
  getchar();
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  getchar();
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
  getchar();
 }
 printf("%d\n", size);
 return size;
}

SeqList insert(Job j , SeqList sl)
{

//Implement this function

	if(sl.size == 0){
		st[sl.head].ele = j;
		st[sl.head].next = -1;

		sl.size++;
		return sl;
	}
	
	int head = sl.head;

	for( int i = 0 ; i < sl.size; i++){
		if(compare(st[head].ele, j) != LESSER){
			Job temp = st[head].ele;
			st[head].ele = j;
			j = temp;
		}
			
		head = st[head].next;
	}

	st[head].next = nextfreeloc;
	st[nextfreeloc].ele = j;
	st[nextfreeloc].next = -1;
	sl.size++;
	nextfreeloc++;

	return sl;

}
  
void insertelements (JobList list , int size, SeqList s[3])
{

// Implement this function
	for (int j = 0 ; j < 3 ; j++)
	{
		int flag = 0;
		for ( int i = 0 ; i < size ; i++)
		{	
			if(list[i].pri == j){
				if(flag == 0){                    
					s[j] = createlist();
					flag++;
				}

				s[list[i].pri] = insert(list[i], s[list[i].pri]);
//				printlist(s[list[i].pri]);
//				printf("\n");
			}
		}
	}
}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{
	int count = 0;
// Implement this function
	for(int i = 2 ; i>=0; i--){
		int size = s[i].size;
		Location temp = st[s[i].head];
		while(size--){
			
			ele[count++] = temp.ele;
			temp = st[temp.next];
		}
	}
}

void printlist(SeqList sl)
{

	int temp = sl.head;
	for (int i = 0 ; i < sl.size ; i++){
		printJob(st[temp].ele);
		temp = st[temp].next;
	}

}

void printJobList(JobList list, int size)
{

// Implement this function
//	printf("%d",size);
	for (int i = 0 ; i < size; i++)
	{
//		printf("%d\n", i);
		printJob(list[i]);
	}

}


void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 insertelements (list, size, seq);
 printf("Now printing in bucket form\n");
 printlist(seq[0]);   
 printlist(seq[1]);
 printlist(seq[2]);
 copy_sorted_ele (seq , list); 
}

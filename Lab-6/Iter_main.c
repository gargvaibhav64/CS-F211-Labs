#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "recMS.h"
#include "IterMS.h"

int si;

int main(){
    FILE * fptr = fopen("1024.txt", "r");

    if(fptr == NULL){
        printf("Couldn't open file");
        exit(1);
    }

    Element * ls = (Element *)malloc(sizeof(Element) * 1024);

    Element * temp = ls;

    int id_count = 0;

    while(fscanf(fptr, "%[^,], %lf", temp->name, &temp->cgpa) > 1){
        //printf("%s, %0.2lf", temp->name, temp->cgpa);

        id_count++;
        temp++;
    }

    mergeSortIter(ls, id_count);
    temp = ls;

    int i = 0;
    while (i < id_count)
    {
        printf("%s, %0.2lf\n", temp->name, temp->cgpa);
        temp++;
        i++;

    }
    

    return 0;
}
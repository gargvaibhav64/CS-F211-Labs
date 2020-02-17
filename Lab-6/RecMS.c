#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "merge.h"
#include "recMS.h"

extern int si;

void mergeSortRec(Element ls[], int size){
    int mid = size/2 ;
    if(size > 1){
        mergeSortRec(ls, mid);
        mergeSortRec(&ls[mid], mid + size%2);
    }
    Element * ls_sorted = (Element *)malloc(sizeof(Element) * size);
    merge(ls, mid, &ls[mid], mid + size%2, ls_sorted);

    for(int i = 0 ; i < size ; i++){
        ls[i] = ls_sorted[i];
    }

    if(size == 1){
        int i;
        si = &i;
    }

    free(ls_sorted);
}
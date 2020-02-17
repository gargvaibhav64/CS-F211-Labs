#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "merge.h"
#include "IterMS.h"

extern int si;

int min(int x, int y) { return (x<y)? x :y; } 

void mergeSortIter(Element ls[], int size){

    int i;
    for(i = 2 ; i < (size ); i*=2){
        for(int j = 0 ; j < size ; j+=i ){

            int mid = j + (i/2);

            int lsize = min(i/2,size-j);
            int rsize = min(i/2, size-j-i/2);

            if(lsize < i/2){
                rsize = 0;
            }
            //rsize = min(rsize, size-j-1);
            Element * ls_sorted = (Element *)malloc(sizeof(Element) * (lsize+rsize));

            merge(&ls[j], lsize, &ls[mid], rsize, ls_sorted);

            int temp = 0;

            for (int k = j ; temp < min(i, lsize + rsize) ;){
                ls[k++] = ls_sorted[temp++];
            }

            free(ls_sorted);
            
        }
    }

    int x = i/2;

    Element * ls_sorted = (Element *)malloc(sizeof(Element) * size);

    merge(ls, x, &ls[x], size - x, ls_sorted);
    for(int k = 0 ; k < size ; k++){
        ls[k] = ls_sorted[k];
    }

    si = &x;

    free(ls_sorted);

}
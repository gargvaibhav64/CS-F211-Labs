//File implementing the functions described in ex2.h
//Compiled along with ex2_main.c

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

extern int si;

struct card * insertInOrder(struct card *arr, int index){

    struct card * temp = &arr[index-1];

    while(arr != temp){

        struct card * prev = temp-1;
        if(prev->num > temp->num){
            struct card a = *prev;
            *prev = *temp;
            *temp = a;
        }
        temp--;

    }
    return arr;
}

struct card * insertionSort(struct card *arr, int size){
    if(size > 1){
        insertionSort(arr, size-1);
    }

    insertInOrder(arr, size);

    if(size == 1){
        int a;
        si = &a;

    }
    return arr;
}




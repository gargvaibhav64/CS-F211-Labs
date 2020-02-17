//File implementing the functions described in ex1.h
//Compiled along with ex1_main.c

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

extern int size_Struct;

struct card * create_arr(struct card * new, FILE * fptr){

    struct card * a = new;

    int i = 0;
    
    while(fscanf(fptr, "\"%lld, %[^,] , %[^,], %[^,], %[^\"]", &a->num, a->bankcode, a->exp_Date, a->first_name, a->last_name) !=-1){
        char ch = fgetc(fptr);

        ch = fgetc(fptr);

        i++;

        if(i >= size_Struct){
            new = realloc(new, (i+1)*sizeof(struct card));
            size_Struct++;
            a = &new[i-1];
            if(a==NULL){
                printf("Realloc error\n");
            }
        }

        a++;
    }

    i = 0;
    a = new;
}
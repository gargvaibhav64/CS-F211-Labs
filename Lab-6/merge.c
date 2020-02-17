//#include <stdio.h>
#include "struct.h"

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]){
    int i = 0;
    int j = 0;
    int k = 0;
    for (; i < sz1 && j < sz2;){
        if(Ls1[i].cgpa < Ls2[j].cgpa){
            Ls[k++] = Ls1[i++];
        }
        else{
            Ls[k++] = Ls2[j++];
        }
    }

    if(i == sz1 && j < sz2){
        while(j < sz2){
            Ls[k++] = Ls2[j++];
        }
    }
    else if((j == sz2 && i < sz1)){
        while(i < sz1){
            Ls[k++] = Ls1[i++];
        }        
    }
    
}
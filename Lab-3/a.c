#include <stdio.h>
#include <stdlib.h>

int funx(){
    int * x = malloc(sizeof(int));

    
    printf("%x\n", x);

    return *x;

}

int main(){
    int x;

    printf("%x\n", &x);

    x = funx();

    printf("%x\n", &x);
    return 0;

}
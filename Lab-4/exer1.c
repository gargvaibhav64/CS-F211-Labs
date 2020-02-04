#include <stdio.h>

int bits;

void p(int n){
    int pilani;
    printf("%u\n", &pilani);
    p(n+1);
}

void g(){
    int goa;
    printf("%u\n", &goa);
}

void h(){
    int hyd;
    printf("%u\n", &hyd);
}

void d(){
    int dub;
    printf("%u\n", &dub);
}

int main(){
    int n=0;
	
    p(n);
    g();
    h();
    d();
    printf("%u\n", &bits);
    return 0;
}

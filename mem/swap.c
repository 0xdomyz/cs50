#include <stdio.h>
void swap(int *a, int *b);

int main(void){

    int i = 1;
    int j = 2;

    printf("x is %i, y is %i\n",i,j);
    swap(&i, &j);
    printf("x is %i, y is %i\n",i,j);
}


void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}
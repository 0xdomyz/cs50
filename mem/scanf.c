#include <stdio.h>
#include <stdlib.h>

int main(void){

    int x;

    printf("x : ");
    scanf("%i", &x);
    printf("x is %i\n", x);

    char *s = malloc(4);
    printf("s : ");
    scanf("%s", s);
    printf("s is %s\n", s);

}


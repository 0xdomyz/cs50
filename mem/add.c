#include <stdio.h>

int main(void){
    int n = 50;
    int *p = &n;
    printf("value of n: %i\n", n);
    printf("position of n: %p\n", p);
    printf("position of n: %p\n", &n);
    printf("value of n: %i\n", *p);

    char *s = "HI!";
    char *o = &s[0];
    printf("string: %s\n", s);
    printf("position of string: %p\n", s);
    printf("position of char: %p\n", o);
    for (int i = 0; i < 5; i++){
        printf("char: %c, position: %p\n", *(s + i), &s[i]);
    }

    int numbers[] = {4,6,8,2,7,5,0};
    for (int i = 0; i< 9; i++){
        printf("%i\n", * (numbers + i));
    }
}
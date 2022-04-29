#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void){
    char *i = get_string("i: ");
    char *j = get_string("j: ");

    printf("%p\n",i);
    printf("%p\n",j);

    if (strcmp(i,j)==0){
        printf("same\n");
    } else {
        printf("diff\n");
    }
}
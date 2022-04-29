#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void){
    char *s = get_string("s: ");

    // char *t = s;
    // t[0] = toupper(t[0]);
    // printf("s: %s\n", s);
    // printf("t: %s\n", t);

    char *r = malloc(strlen(s)+1);
    // for (int i = 0, n = strlen(s); i<n; i++){
    //     r[i] = s[i];
    // }
    strcpy(r, s);
    if (strlen(r)>0){
        r[0] = toupper(r[0]);
    }
    printf("s: %s\n", s);
    printf("r: %s\n", r);


}
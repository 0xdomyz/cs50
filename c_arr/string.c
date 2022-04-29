# include <stdio.h>
# include <string.h>
# include <ctype.h>

int string_length(char* string) {
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }
    return i;
}

int main(void){

    // from char
    char string[4] = "Hai";
    printf("%s\n", string);
    printf("%c%c%c%c\n", string[0], string[1], string[2], string[3]);

    // length
    char name[5] = "Haii";
    printf("%i\n", string_length(name));
    printf("%i\n", strlen(name));
    for (int i = 0, l = strlen(name); i < l; i ++) {
        printf("%c", name[i]);
    }
    printf("\n");

    // upper
    char name2[5] = "haii";
    for (int i = 0, l = strlen(name2); i < l; i ++) {
        if (name2[i] >= 'a' && name2[i] <= 'z') {
            printf("%c", (int) name2[i] - 32);
        }else {
            printf("%c", name2[i]);
        }
    }
    printf("\n");

    for (int i = 0, l = strlen(name2); i < l; i ++) {
        if (islower(name2[i])) {
            printf("%c", (int) name2[i] - 32);
        }else {
            printf("%c", name2[i]);
        }
    }
    printf("\n");

    for (int i = 0, l = strlen(name2); i < l; i ++) {
        printf("%c", toupper(name2[i]));
    }
    printf("\n");

}



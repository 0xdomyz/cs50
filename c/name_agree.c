#include <stdio.h>

int main(void)
{
    char answer[100];
    printf("name? ");
    gets(answer);
    printf("\nhello, %s\n", answer);

    char c;
    printf("agree? ");
    scanf("%c", &c);
    if (c == 'y' || c == 'Y') {
        printf("yes");
    } else if (c == 'n' || c == 'N') {
        printf("no");
    } else if (c == 'n' && c == 'N') {
        printf("not reach");
    } else {
        printf("ignores");
    }
}
#include <stdio.h>

int main(void)
{
    long points;
    const int MINE = 2;
    printf("points: ");
    scanf("%d", &points);
    if (points < MINE) {
        printf("less");
    }
    else if (points > MINE){
        printf("more");
    }
    else {
        printf("equal");
    }

    printf("\n");

    if (points % 2 == 0) {
        printf("even");
    }
    else if (points % 2 == 1){
        printf("odd");
    }
    else {
        printf("not even nor odd");
    }
}
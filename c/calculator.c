#include <stdio.h>

int main(void)
{
    // long x;
    // long y;
    // printf("x: ");
    // scanf("%d", &x);
    // printf("y: ");
    // scanf("%d", &y);
    // long z = x + y;
    // printf("%li\n", z);

    float x;
    float y;
    printf("x: ");
    scanf("%f", &x);
    printf("y: ");
    scanf("%f", &y);
    float z = x / y;
    printf("%.50f\n", z);
}
#include <stdio.h>
#include <math.h>

int main(void)
{
    float amount;
    printf("dollar: ");
    scanf("%f", &amount);
    int pennies = round(amount * 100);
    int pennies2 = amount * 100;
    printf("%i\n", pennies);
    printf("%i\n", pennies2);
}
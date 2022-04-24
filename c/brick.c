#include <stdio.h>

int main(void)
{
    int n;
    do {
        printf("width: ");
        scanf("%d", &n);
    }
    while (n < 1);

    int m;
    while (1){
        printf("height: ");
        scanf("%d", &m);
        if (m>1){
            break;
        }
    }

    for (int i = 0;i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("#");
        }
        printf("\n");
    }

}



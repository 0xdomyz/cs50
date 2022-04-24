#include <stdio.h>
void ccc(int n);

int main(void)
{
    int i = 1;
    while (i <= 3) {
        printf("aaa\n");
        i++;
    }

    ccc(4);

}


void ccc(int n){
    for (int j = 0; j<n; j++) {
        printf("ccc\n");
    }
}


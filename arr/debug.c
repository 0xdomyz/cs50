# include <stdio.h>
int get_neg_int(void);

int main(void){

    int j = get_neg_int();
    printf("%i",j);

    for (int i = 0; i <= 3; i++) {
        printf("#\n");
    }
}


int get_neg_int(void) {
    int n;
    do {
        printf("neg int? ");
        scanf("%i", &n);
    } while (n < 0);
    return n;
}


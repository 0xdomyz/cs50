# include <stdio.h>

int get_int(char* msg) {
    int n;
    printf("%s", msg);
    scanf("%i", &n);
    return n;
}

int main(void){
    int score[3];

    for (int i = 0; i < 3; i++) {
        score[i] = get_int("Score: ");
    }

    printf("avg: %f", (score[0] + score[1] + score[2])/3.0);

}


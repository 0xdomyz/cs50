# include <stdio.h>

int main(int argc, char* argv[]){

    if (argc == 2) {
        printf("aaa, %s", argv[1]);
    } else {
        printf("arg not right");
        return 1;
    }

}



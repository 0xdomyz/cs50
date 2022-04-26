#include <stdio.h>
#include <stdlib.h>

int main(void){
    // int list[3];

    // list[0] = 1;
    // list[1] = 2;
    // list[2] = 3;

    // for (int i = 0; i < 3; i++){
    //     printf("%i\n", list[i]);
    // }

    //dyn alloc array of size 3
    int *list = malloc(3 * sizeof(int));
    if(list==NULL){
        return 1;
    }

    // assin 3 numb to i
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // resize odl to size 4
    // int *tmp = malloc(4 * sizeof(int));
    int *tmp = realloc(list, 4 * sizeof(int));
    if(tmp==NULL){
        free(list);
        free(tmp);
        return 1;
    }

    // copy old to new
    // for (int i = 0; i<3; i++){
    //     tmp[i] = list[i];
    // }

    // add 4th in
    tmp[3] = 4;

    // free old mem
    // free(list);
    list = tmp;

    for (int i = 0; i<4; i++){
        printf("%i\n",list[i]);
    }

    // free stuff
    free(list);
    return 0;
}
#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct 
{
    string name;
    string number;
}
person;

int main(void)
{

    person people[2];

    people[0].name = "aaa";
    people[0].number = "+12-34";
    people[1].name = "bbb";
    people[1].number = "+43-21";

    for (int i = 0; i < 2; i++){
        if (strcmp(people[i].name, "aaa") == 0){
            printf("found %s\n", people[i].number);
            return 0;
        }
    }
    printf("not found\n");
    return 1;

}



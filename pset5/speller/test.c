#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    char word[45 + 1];
    struct node *next;
}
node;
int array[5] = {0, 1, 2, 3, 4};
node *table[25];

int main(void)
{

    for(int o = 0; o < 25; o++)
    {

        table[o] = 0;
        printf("%p", table[o]);
    }
    printf("\n");

    node *labas = malloc(sizeof(node));
    for (int i = 0; i < 5; i++)
    {
        if(table[1] == 0){
        strcpy(labas->word, "zdare");
        labas->next = NULL;
        table[1] = labas;
        printf("%s\n", table[1]->word);
        }
        else {
            node *viso = malloc(sizeof(node));
            strcpy(viso->word, "ka tu pleybojau");
            viso->next = table[1];
            table[1] = viso;
            printf("%s\n", table[1]->word);
            printf("$$$");
        }

    }

    printf("%s\n", table[1]->next->next->next->next->word);
}
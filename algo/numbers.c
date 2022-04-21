#include <cs50.h>
#include <stdio.h>


int main (void)
{
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};

    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == 0)
        {
            // return 0 kai programa baigiasi sėkmingai
            printf("Found\n");
            return 0;
        }
    }
    // return 1 arba bet koks kitas skaičius, kaip 404, kai programa baigiasi nesėkmingai
    printf("Not found\n");
    return 1;
}
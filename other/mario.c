#include <cs50.h>
#include <stdio.h>

    int main (void)
    {
        int height;
        int one = 1;


        do
        {
        height = get_int("Height: ");
        }
        while ( height > 8 || height <= 0 );




        for (int j = 0; j<=height; j++)
        {

        for (int i = 2; i<=height; i++)
        {


            printf(" ");

        }
        if (height != 0)
        {


        for (int k = 0; k < one ; k++)
        {
            printf("#");
        }
        printf("  ");
         for (int k = 0; k < one; k++)
        {
            printf("#");
        }
        }

        printf("\n");
        height--;
        one++;
        j = 0;
        }
    }

    // int c = 0;
    // do
    // {
    //     printf("#");
    //     c++;
    // }
    // while ( height != c );
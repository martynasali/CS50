#include <cs50.h>
#include <stdio.h>

int main (void)
    {
        int height;
        int eight = 1;

        do
        {
        height = get_int("Height: ");
        }
        while ( height > 8 || height <= 0 );



        for (int d = 0; d < 8; d++)
        {


            for (int e = 0; e < eight; e++)

            {
               
                }
                printf("#");

            }


            printf("\n");
            eight++;
        }




    }
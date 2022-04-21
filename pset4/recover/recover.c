#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int read(uint8_t *buffer, FILE *file);
int t = 0;
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    uint8_t *buffer = malloc(512);

    FILE *file = fopen(argv[1], "r");
    read(buffer, file);

}

int read(uint8_t *buffer, FILE *file)
{

    // read file
    int tw = 0;
    int i = 0;
    while (i != 50)
    {
    t = 0;

    // check if its jpg
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        char *filename = malloc(7);
        sprintf(filename, "%03i.jpg", i);
        FILE *img = fopen(filename, "w");
        i++;

    // write the file
        do
        {
            fwrite(buffer, 1, 512, img);
            tw = fread(buffer, 1, 512, file);
            printf("kiek");
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                t = 100;
            }
        else if (tw != 512 && i == 50)
            {
                t = 100;
            }
        }
        while(t < 100);


    }

    else
    {
            tw = fread(buffer, 1, 512, file);
    }

    }


    return 0;


}
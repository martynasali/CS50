#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float gray = (float)(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
            gray = round(gray);
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtRed = gray;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
        }
    }

    for (int k = 0; k < height; k++)
    {
        int widthR = width;
        for (int l = -1; l < width; l++)
        {

            image[k][widthR].rgbtBlue = copy[k][l].rgbtBlue;
            image[k][widthR].rgbtGreen = copy[k][l].rgbtGreen;
            image[k][widthR].rgbtRed = copy[k][l].rgbtRed;
            widthR--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
        }
    }

    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            // Corner left top
            if (l == 0 && k == 0)
            {
                image[k][l].rgbtBlue = (float)(copy[k][l].rgbtBlue
                + copy[k][l+1].rgbtBlue + copy[k+1][l].rgbtBlue
                + copy[k+1][l+1].rgbtBlue)/4;
                image[k][l].rgbtBlue = round(image[k][l].rgbtBlue);
                image[k][l].rgbtGreen = round((float)(copy[k][l].rgbtGreen
                + copy[k][l+1].rgbtGreen + copy[k+1][l].rgbtGreen
                + copy[k+1][l+1].rgbtGreen)/4);
                image[k][l].rgbtRed = round((float)(copy[k][l].rgbtRed
                + copy[k][l+1].rgbtRed + copy[k+1][l].rgbtRed
                + copy[k+1][l+1].rgbtRed)/4);
            }
            // corner right top
            else if(l == (width-1) && k == 0)
            {
                image[k][l].rgbtBlue = round((float)(copy[k][l].rgbtBlue
                + copy[k][l-1].rgbtBlue + copy[k+1][l].rgbtBlue
                + copy[k+1][l-1].rgbtBlue)/4);
                image[k][l].rgbtGreen = round((float)(copy[k][l].rgbtGreen
                + copy[k][l-1].rgbtGreen + copy[k+1][l].rgbtGreen
                + copy[k+1][l-1].rgbtGreen)/4);
                image[k][l].rgbtRed = round((float)(copy[k][l].rgbtRed
                + copy[k][l-1].rgbtRed + copy[k+1][l].rgbtRed
                + copy[k+1][l-1].rgbtRed)/4);
            }
            // corner bottom left
            else if(l == 0 && k == (height-1))
            {
                image[k][l].rgbtBlue = round((float)(copy[k][l].rgbtBlue
                + copy[k][l+1].rgbtBlue + copy[k-1][l].rgbtBlue
                + copy[k-1][l+1].rgbtBlue)/4);
                image[k][l].rgbtGreen = round((float)(copy[k][l].rgbtGreen
                + copy[k][l+1].rgbtGreen + copy[k-1][l].rgbtGreen
                + copy[k-1][l+1].rgbtGreen)/4);
                image[k][l].rgbtRed = round((float)(copy[k][l].rgbtRed
                + copy[k][l+1].rgbtRed + copy[k-1][l].rgbtRed
                + copy[k-1][l+1].rgbtRed)/4);
            }
            // corner bottom right
            else if(l == (width-1) && k == (height-1))
            {
                image[k][l].rgbtBlue = round((float)(copy[k][l].rgbtBlue
                + copy[k][l-1].rgbtBlue + copy[k-1][l].rgbtBlue
                + copy[k-1][l-1].rgbtBlue)/4);
                image[k][l].rgbtGreen = round((float)(copy[k][l].rgbtGreen
                + copy[k][l-1].rgbtGreen + copy[k-1][l].rgbtGreen
                + copy[k-1][l-1].rgbtGreen)/4);
                image[k][l].rgbtRed = round((float)(copy[k][l].rgbtRed
                + copy[k][l-1].rgbtRed + copy[k-1][l].rgbtRed
                + copy[k-1][l-1].rgbtRed)/4);
            }
            // top row
            else if (l != 0 && k == 0)
            {
                if (l != (width-1))
                {
                image[k][l].rgbtBlue = round((float)(copy[k][l].rgbtBlue
                + copy[k][l+1].rgbtBlue + copy[k][l-1].rgbtBlue
                + copy[k+1][l].rgbtBlue + copy[k+1][l+1].rgbtBlue
                + copy[k+1][l-1].rgbtBlue)/6);
                image[k][l].rgbtGreen = round((float)(copy[k][l].rgbtGreen
                + copy[k][l+1].rgbtGreen+ copy[k][l-1].rgbtGreen
                + copy[k+1][l].rgbtGreen
                + copy[k+1][l+1].rgbtGreen+ copy[k+1][l-1].rgbtGreen)/6);
                image[k][l].rgbtRed = round((float)(copy[k][l].rgbtRed
                + copy[k][l+1].rgbtRed
                + copy[k][l-1].rgbtRed + copy[k+1][l].rgbtRed
                + copy[k+1][l+1].rgbtRed + copy[k+1][l-1].rgbtRed)/6);
                }
            }

            // left row
            else if( k != 0 && l == 0 )
            {
                if ( k != (height-1))
                {
                image[k][l].rgbtBlue = round((float)(copy[k][l].rgbtBlue
                + copy[k][l+1].rgbtBlue + copy[k-1][l].rgbtBlue
                + copy[k+1][l].rgbtBlue
                + copy[k-1][l+1].rgbtBlue + copy[k+1][l+1].rgbtBlue)/6);
                image[k][l].rgbtGreen = round((float)(copy[k][l].rgbtGreen
                + copy[k][l+1].rgbtGreen
                + copy[k-1][l].rgbtGreen + copy[k+1][l].rgbtGreen
                + copy[k-1][l+1].rgbtGreen
                + copy[k+1][l+1].rgbtGreen)/6);
                image[k][l].rgbtRed = round((float)(copy[k][l].rgbtRed
                + copy[k][l+1].rgbtRed + copy[k - 1][l].rgbtRed
                + copy[k+1][l].rgbtRed + copy[k - 1][l + 1].rgbtRed
                + copy[k+1][l+1].rgbtRed)/6);
                }
            }
             // right row
            else if( k != 0 && l == (width-1) )
            {
                if ( k != (height-1))
                {
                image[k][l].rgbtBlue = round((float)(copy[k][l].rgbtBlue
                + copy[k][l-1].rgbtBlue + copy[k-1][l].rgbtBlue
                + copy[k+1][l].rgbtBlue + copy[k+1][l-1].rgbtBlue
                + copy[k-1][l-1].rgbtBlue)/6);
                image[k][l].rgbtGreen = round((float)(copy[k][l].rgbtGreen
                + copy[k][l-1].rgbtGreen+ copy[k-1][l].rgbtGreen
                + copy[k+1][l].rgbtGreen
                + copy[k+1][l-1].rgbtGreen+ copy[k-1][l-1].rgbtGreen)/6);
                image[k][l].rgbtRed = round((float)(copy[k][l].rgbtRed
                + copy[k][l-1].rgbtRed + copy[k-1][l].rgbtRed
                + copy[k+1][l].rgbtRed
                + copy[k+1][l-1].rgbtRed + copy[k-1][l-1].rgbtRed)/6);
                }
            }

            // bottom row
            else if( k == (height-1) && l != 0 )
            {
                if ( l != (width-1))
                {
                image[k][l].rgbtBlue = round((float)(copy[k][l].rgbtBlue
                + copy[k][l+1].rgbtBlue + copy[k][l-1].rgbtBlue
                + copy[k-1][l].rgbtBlue + copy[k-1][l+1].rgbtBlue
                + copy[k-1][l-1].rgbtBlue)/6);
                image[k][l].rgbtGreen = round((float)(copy[k][l].rgbtGreen
                + copy[k][l+1].rgbtGreen+ copy[k][l-1].rgbtGreen
                + copy[k-1][l].rgbtGreen+ copy[k-1][l+1].rgbtGreen
                + copy[k-1][l-1].rgbtGreen)/6);
                image[k][l].rgbtRed = round((float)(copy[k][l].rgbtRed
                + copy[k][l+1].rgbtRed+ copy[k][l-1].rgbtRed
                + copy[k-1][l].rgbtRed+ copy[k-1][l+1].rgbtRed
                + copy[k-1][l-1].rgbtRed)/6);
                }
            }


            // all else
            else
            {
            image[k][l].rgbtBlue = round((float)(copy[k][l].rgbtBlue
            + copy[k-1][l].rgbtBlue + copy[k+1][l].rgbtBlue
            + copy[k][l+1].rgbtBlue + copy[k][l-1].rgbtBlue
            + copy[k+1][l+1].rgbtBlue + copy[k+1][l-1].rgbtBlue
            + copy[k-1][l+1].rgbtBlue + copy[k-1][l-1].rgbtBlue)/9);
            image[k][l].rgbtGreen =  round((float)(copy[k][l].rgbtGreen
            + copy[k-1][l].rgbtGreen + copy[k+1][l].rgbtGreen
            + copy[k][l+1].rgbtGreen
            + copy[k][l-1].rgbtGreen + copy[k+1][l+1].rgbtGreen
            + copy[k+1][l-1].rgbtGreen
            + copy[k-1][l+1].rgbtGreen + copy[k-1][l-1].rgbtGreen)/9);
            image[k][l].rgbtRed = round((float)(copy[k][l].rgbtRed
            + copy[k-1][l].rgbtRed + copy[k+1][l].rgbtRed
            + copy[k][l+1].rgbtRed + copy[k][l-1].rgbtRed
            + copy[k+1][l+1].rgbtRed + copy[k+1][l-1].rgbtRed
            + copy[k-1][l+1].rgbtRed + copy[k-1][l-1].rgbtRed)/9);
            }
        }
    }

    return;
}



// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height+2][width+2];


    for (int o = 0; o < height+2; o++)
    {
        for (int p = 0; p < width+2; p++)
    {
        // null copy
            copy[o][p].rgbtBlue = 0;
            copy[o][p].rgbtGreen = 0;
            copy[o][p].rgbtRed = 0;
    }

    }

    // make a copy
    for(int q = 1; q < height+1; q++ )
    {
        for (int w = 1; w < width+1; w++ )
        {
            copy[q][w].rgbtBlue = image[q-1][w-1].rgbtBlue;
            copy[q][w].rgbtGreen = image[q-1][w-1].rgbtGreen;
            copy[q][w].rgbtRed = image[q-1][w-1].rgbtRed;
        }
    }



    for (int k = 1; k < height+1; k++)
    {
        for (int l = 1; l < width+1; l++)
        {
            float blueGX = round((float)(0 * (copy[k][l].rgbtBlue
            + copy[k-1][l].rgbtBlue + copy[k+1][l].rgbtBlue))
            + (2 * copy[k][l+1].rgbtBlue) + (-2*copy[k][l-1].rgbtBlue)
            + (1 * copy[k+1][l+1].rgbtBlue) + (-1*copy[k+1][l-1].rgbtBlue)
            + (1*copy[k-1][l+1].rgbtBlue) + (-1 * copy[k-1][l-1].rgbtBlue));
            float blueGY = round((float)(0 * (copy[k][l].rgbtBlue
            + copy[k][l-1].rgbtBlue + copy[k][l+1].rgbtBlue))
            + (2 * copy[k+1][l].rgbtBlue) + (-2*copy[k-1][l].rgbtBlue)
            + (1 * copy[k+1][l+1].rgbtBlue) + (1*copy[k+1][l-1].rgbtBlue)
            + (-1*copy[k-1][l+1].rgbtBlue) + (-1 * copy[k-1][l-1].rgbtBlue));
            float blueF = (float)round(sqrt((blueGX * blueGX)+(blueGY * blueGY)));
            if (blueF > 255)
            {blueF = 255;}
            image[k-1][l-1].rgbtBlue = blueF;


            float greenGX = round((float)(0 * (copy[k][l].rgbtGreen
            + copy[k-1][l].rgbtGreen+ copy[k+1][l].rgbtGreen))
            + (2 * copy[k][l+1].rgbtGreen) + (-2*copy[k][l-1].rgbtGreen)
            + (1 * copy[k+1][l+1].rgbtGreen) + (-1*copy[k+1][l-1].rgbtGreen)
            + (1*copy[k-1][l+1].rgbtGreen) + (-1 * copy[k-1][l-1].rgbtGreen));
            float greenGY = round((float)(0 * (copy[k][l].rgbtGreen
            + copy[k][l-1].rgbtGreen+ copy[k][l+1].rgbtGreen))
            + (2 * copy[k+1][l].rgbtGreen) + (-2*copy[k-1][l].rgbtGreen)
            + (1 * copy[k+1][l+1].rgbtGreen) + (1*copy[k+1][l-1].rgbtGreen)
            + (-1*copy[k-1][l+1].rgbtGreen) + (-1 * copy[k-1][l-1].rgbtGreen));
            float greenF = (float)round(sqrt((greenGX * greenGX)+(greenGY * greenGY)));
            if (greenF > 255)
            {greenF = 255;}
            image[k-1][l-1].rgbtGreen = greenF;


            float redGX = round((float)(0 * (copy[k][l].rgbtRed
            + copy[k-1][l].rgbtRed + copy[k+1][l].rgbtRed))
            + (2 * copy[k][l+1].rgbtRed) + (-2*copy[k][l-1].rgbtRed)
            + (1 * copy[k+1][l+1].rgbtRed) + (-1*copy[k+1][l-1].rgbtRed)
            + (1*copy[k-1][l+1].rgbtRed) + (-1 * copy[k-1][l-1].rgbtRed));
            float redGY = round((float)(0 * (copy[k][l].rgbtRed
            + copy[k][l-1].rgbtRed + copy[k][l+1].rgbtRed))
            + (2 * copy[k+1][l].rgbtRed) + (-2*copy[k-1][l].rgbtRed)
            + (1 * copy[k+1][l+1].rgbtRed) + (1*copy[k+1][l-1].rgbtRed)
            + (-1*copy[k-1][l+1].rgbtRed) + (-1 * copy[k-1][l-1].rgbtRed));
            float redF = (float)round(sqrt((redGX * redGX)+(redGY * redGY)));
            if (redF > 255)
            {redF = 255;}
            image[k-1][l-1].rgbtRed = redF;

        }
    }


    return;
}

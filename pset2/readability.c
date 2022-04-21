#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
int countLetters(string text );
int countWords(string text);
int countSent(string text);

int notLetters[] = {32, 33, 44, 39, 45, 58, 59, 34, 46, 63};
int sentEnd[] = {46, 33, 63};
int main (void)
{
    string text = get_string("Text: ");
    int letters = countLetters(text);
    int words = countWords(text);
    int sent = countSent(text);
    float L = ((float)letters / words) * 100;
    float S = ((float)sent / words) * 100;
    float index = 0.0588 * L -0.296 * S - 15.8;
    int result = round(index);
    if (result >= 16)
    {
    printf("Grade 16+\n");
    }
    else if (result < 1 )
    {
    printf("Before Grade 1\n");
    }
    else
    {
    printf("Grade %i\n", result);
    }
}

int countLetters (string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++ )
    {
            letters++;
        for(int j = 0; j < 10; j++)
         {
             if(text[i] == notLetters[j] )
            {
                letters--;
            }
         }
    }
    return letters;
}

int countWords (string text)
{
    int words = 1;

     for (int i = 0, n = strlen(text); i < n; i++ )
    {
        if(text[i] == 32)
        {
            words++;
        }
    }
    return words;
}

int countSent(string text)
{
    int sent = 0;
    for (int i = 0, n = strlen(text); i < n; i++ )
    {
        for(int j = 0; j < 3; j++)
         {
             if(text[i] == sentEnd[j] )
            {
                sent++;
            }
         }
    }

    return sent;
}
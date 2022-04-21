#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc(strlen(s)+1);
    if (t == NULL)
    {
        return 1;
    }

    // strcpy(t, s); kopijavimo funcija

    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        // tas pats kaip*(t+i) = *(s+i);
        t[i] = s[i];
    }
    // jei vartotojas nieko neįveda
    if(strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }
    // tas pats kaip nes t yra pointeris *t = toupper(*t);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
    
    free(t); 
    // valgrand -- patikrina ar viskas gerais su memory
}

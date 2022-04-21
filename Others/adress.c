#include <stdio.h>

int main (void)
{
    int n = 50;
    int *p = &n;
    printf("%i\n", *p);

    char *s = "hi!";
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));
}
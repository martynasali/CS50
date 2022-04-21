#include <cs50.h>
#include <stdio.h>

    int c = 0;


int collatz (n)
{
    if (n == 1)
    return c;

    if(n%2 == 0)
    {
        c++;
        collatz (n/2);
    }

    else
    {
        c++;
        collatz (3 * n +1);
        return c;
    }
    return c;
}

int main(void)
{
    int n = get_int("enter your number:\n");

    int t = collatz(n);
    printf("%i", t);
    return 0;
}
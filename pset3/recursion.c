#include <cs50.h>
#include <stdio.h>


int recursion(n)
{
    printf("%i ", n);
    if (n  != 50)
    {
       recursion(n + 1);
    }
    else
    return 0;


    return 0;
}


int main(void)
{
    recursion(1);
    return 0;
}
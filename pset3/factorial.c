#include <cs50.h>
#include <stdio.h>


int factorial(n)
{

   if(n != 1)
   {

    return   n * factorial(n - 1);
   }
   else
   return n;

    return 0;
}


int main(void)
{
    int n = get_int("enter factorial: \n");
    n = factorial(n);
     printf("%i\n", n);
    return 0;
}
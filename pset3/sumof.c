#include <cs50.h>
#include <stdio.h>


int sumof(n)
{
 if (n == 0)
 return n;
 else
 {
     
    return n % 10 + sumof(n /10);
 }
   return 0;
}


int main(void)
{
    int n = get_int("enter number: \n");
    n = sumof(n);
    printf("%i\n", n);
    return 0;
}
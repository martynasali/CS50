#include <cs50.h>
#include <stdio.h>

int main(void)

{
    // get a numbers from user
    int x = get_int("x: ");
    int y = get_int("y: ");
    
    float z = (float) x / y;
    
    printf("%f\n", z);
}
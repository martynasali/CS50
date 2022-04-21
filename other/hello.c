#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //asks name
    string answer = get_string("Whats your name? ");
    //prints name
    printf("hello, %s\n", answer);

}
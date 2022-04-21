#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int pop;
    int end;
    int born;
    int dead;
    int year;
    int i = 0;

    //starting population
    do
   {
    pop = get_int("Start size: ");
   }
   while (pop < 9);




    //ending size
    do
    {
      end = get_int("End size: ");
    }
    while (end < pop);


    if(end != pop)
    {
       do
     {
       born = pop / 3;

       dead = pop / 4;

       year = born - dead;

      pop += year;

      i++;

     }

   while (pop < end);
}
else
{
 i = 0;
}


   // int result = (end - pop) / year;

     printf("Years: %i\n", i);

}

#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
   string name;
   string number;
}
person;

const int NUMBER = 10;

int main()
{
   person people[NUMBER];

   for (int j = 0; j < NUMBER; j++)
   {
      people[j].name = get_string("Whats the name?");
      people[j].number = get_string("Whats the number?");
   }

   // people[0].name = "Brian";
   // people[0].number = "+1-617-495-1000";

   // people[1].name = "David";
   // people[1].number = "+1-949-468-2750";


   for(int i = 0; i < NUMBER; i++)
   {
      //  if (strcmp(people[i].name, "David") == 0)
      //  {
      //     printf("Found %s\n", people[i].number);
      //     return 0;
      //  }


       printf("Found %s %s\n", people[i].number, people[i].name);
   }
   // printf("Not found");
   // return 1;
}
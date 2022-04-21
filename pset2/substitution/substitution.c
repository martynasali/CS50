#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
string changeLetters ( string argv[], string text);
char lowercase[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
int uppercase[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
int notLetters[] = {32, 33, 44, 39, 45, 58, 59, 34, 46, 63, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57};
int e = 0;
int z = 0;
int main (int argc, string argv[])
{

   if (argc < 2)
   {
    printf("Key must contain 26 characters.\n");
   return 1;
   }

    if(strlen(argv[1]) < 26 )
    {
        printf("Key must contain 26 characters.\n");

        return 1;
    }

   for (int w = 0; w < 26; w++)
   {
    if((int)argv[1][w] <65 || (int)argv[1][w] > 122  )
    {
     printf("invalid characters\n");

        return 1;
    }



    for( e = 0; e < 26; e++)
    {
     if(argv[1][w] == argv[1][e])
     {

      z++;
      if(z >= 2)
      {
      printf("Key invalid\n");

        return 1;
      }

     }



    }

    z=0;
   }


    string text = get_string("plaintext: ");
    changeLetters(argv, text);


}

// vchprzgjntlskfbdqwaxeuymo abcdefghijklmnopqrstuvwxyzi

 string changeLetters ( string argv[], string text)
 {


  int l = strlen(argv[1]);
  char raides[l];

     for (int i = 0; i < l; i++)
     {
        //  printf("%i ", argv[1][i]);
         raides[i] = argv[1][i];
         lowercase[i] = tolower(raides[i]);
         uppercase[i] = toupper(raides[i]);

     }
     printf("ciphertext: ");

    for (int j = 0, n = strlen(text); j <= n-1; j++)
    {

       for(int g = 0; g <= 18; g++)
       {
      if((int)text[j] == notLetters[g] )
      {
       printf("%c", text[j]);
      }
       }

    int lx = (int)text[j];

    if(lx > 64)
    {

       int d = (int)text[j] - 97;

       if(d < 0)
       {
        d = d + 32;
      printf("%c", uppercase[d]);
       }
       else
   {
       printf("%c", lowercase[d]);
   }

    }}
    printf("\n");
     return 0;
 }
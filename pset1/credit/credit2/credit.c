#include <cs50.h>
#include <stdio.h>

long calculate(long a);
long first(long a, int b, int c, int d);
long checksum(long a, int b);
int num;
int dvig;
int vinas;
int antas;
int sum;
int galinis;
int main (void)
{
      long credit = get_long("Enter your credit card number: ");
      int lenght = calculate(credit);
      checksum(credit, num);
    
      int firstN = first(credit, num, sum, lenght);
   




}

long checksum (long a, int b)
{


    for (int i = 1; i < b+2; i++)
    {
        int vienas = a % 10;
        a = (a - vienas)/10;

       if (i % 2 == 0)
       {
           dvig = vienas * 2;
           if(dvig >= 10)
           {
               sum += dvig % 10;
               sum++;

            
           }
           else
           {
           sum += dvig;
       
           }

       }
       else
       {
           sum += vienas;
       }

    }

     return sum;
}



long calculate (long a)
{
    do
    {
        int one = a % 10;

        a = (a - one) / 10;
        num++;
    }
    while(a > 9);


    num+=1;

    return num;
}


long first (long a, int b, int c, int d)
{
    // printf("%lia", a);
    // printf("%ib", b);
    // printf("%ic", c);
    // printf("%id", d);
    long aa = a;

    for(int r = 1; r-1 < b; r++)

    {
        vinas = a % 10;
        a = (a - vinas) / 10;
    }

        for(int rr = 1; rr < b; rr++)

    {
        antas = aa % 10;
        aa = (aa - antas) / 10;
        
    }

    int visa = vinas;
    vinas = (vinas * 10) + antas;
   
     if(d < 13 || d > 16 )
    {
        printf("INVALID\n");

        if(d == 14)
        {
            printf("INVALID\n");
        }
    }

    else if (c % 10 == 0)
      {
           

         if (vinas == 34 || vinas == 37 )
        {
            printf("AMEX\n");
        }
        else if (visa == 4)
        {
            printf("VISA\n");
        }
        else if (vinas == 51 || vinas == 52 || vinas == 53 || vinas == 54 || vinas == 55)
        {
            printf("MASTERCARD\n");
        }
        else
        {

          printf("INVALID\n");
         }
      }
      else
      {

          printf("INVALID\n");
      }








    return vinas;
}
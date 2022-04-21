#include <cs50.h>
#include <stdio.h>


int main (void)
{
    long credit = get_long("Enter your credit card number: ");
    long pirminiai = credit;
    int num = 1;
    int one = 0;
    int two = 0;
    int three = 0;
    int four = 0;
    int sumcheck = 0;
    int lastNum = 0;
    do
    {
        one = credit % 10;
        // printf("%i \n", one);
        credit = (credit - one) / 10;
        // three = credit % 10;
        // credit = (credit - three) / 10;
        // four = credit % 10;
        // credit = (credit - four) / 10;
        if ( num % 2 == 0)
        {
            one = one * 2;
            if (one > 10)
            {
                two = one % 10;
                // printf("dvigubas skaicius %i\n", two);
                sumcheck += two;

                three = one - two;
                // printf("dvigubas skaicius pirmas %i\n", three);
                if(three == 10)
                {
                    sumcheck++;
                }
                sumcheck -= one;

            }
           sumcheck += one;
        //   printf("sumcheckRUNS%i\n", one);
        }
        else
        {
            sumcheck += one;
        }


        num++;
        // printf("%i numeris\n", num);

    }
     while(credit > 9);
    // printf( "paskutinis %li \n", credit );
    lastNum = credit;

    if ( num % 2 == 0)
    {
        one = (int) credit;
        one *= 2;
        // printf("paskutinis skaičius lyginis %i\n", one);

        if (one > 10)
            {
                two = one % 10;
                // printf("dvigubas skaicius %i\n", two);
                sumcheck += two;

                three = one - two;
                // printf("dvigubas skaicius pirmas %i\n", three);
                if(three == 10)
                {
                    sumcheck++;
                }

            }
        else
        {
            sumcheck += one;
        }
    printf("SUMCHECK%i\n", sumcheck);



    }
    printf("SUMCHECK%i\n", sumcheck);

    if (sumcheck % 10 == 0)
    {
        if (lastNum == 3)
        {
            printf("AMEX\n");
        }
        if (lastNum == 4)
        {
            printf("VISA\n");
        }
        if (lastNum == 5)
        {
            printf("MASTERCARD\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }


}
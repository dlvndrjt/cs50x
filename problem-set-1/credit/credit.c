#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Do-while loop for user's input.
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0 || number > 10000000000000000); //total 17 digits

    //Checksum
    int firstn;
    int secondn;
    long n1 = number;
    long n2 = number;
    long lastNumber1;
    long lastNumber2;
    long everyOther;
    long cal1 = 0;
    long cal2 = 0;
    int calx = 0;
    while (n1 > 0)
    {
        lastNumber1 = round(n1 / 10);  //division to get rid of last number of credit card
        everyOther = round(lastNumber1 % 10);  //remainder after above which yeilds the last-number(everyOtherNumber)
        n1 = n1 / 100;  //get rid of the last two digits from number
        cal1 = everyOther * 2;  // multiplication stage
        firstn = round(cal1 / 10);  // first number
        secondn = round(cal1 % 10);  // second number
        calx = firstn + secondn + calx;  // adding firstn(divided everyOther), secondn, and cal1x together
    }

    while (n2 > 0)
    {
        lastNumber2 = round(n2 % 10);
        n2 = n2 / 100;
        cal2 = cal2 + lastNumber2;
    }

    int final = calx + cal2;

    // Verification and linking of number.
    int validity = final % 10;
    int VISA1 = number / 1000000000000;
    int VISA2 = number / 1000000000000000;
    int AMEX = number / 10000000000000;
    int MC = number / 100000000000000;
    if (validity > 0)
    {
        printf("INVALID\n");
    }
    else if (AMEX == 34 || AMEX == 37)
    {
        printf("AMEX\n");
    }
    else if (MC >= 51 && MC <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if (VISA1 == 4 || VISA2 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Do-while loop for user's input.
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change <= 0);

    //Rounding change & naming it as cents.
    int cents = round(change * 100);

    //Simple division to get the number of coins used and the remainder of cents.
    int q1 = round(cents / 25);
    int q2 = round(cents % 25);

    int d1 = round(q2 / 10);
    int d2 = round(q2 % 10);

    int n1 = round(d2 / 5);
    int n2 = round(d2 % 5);

    int p1 = round(n2 / 1);

    //Addition of coins used & printing it out.
    int coins = q1 + d1 + n1 + p1;
    printf("Coins: %i\n", coins);
}

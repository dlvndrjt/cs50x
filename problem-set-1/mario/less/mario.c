#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Do-while loop for user's input.
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    //While loop with two for loops nested within for printing a pyramid.
    int x = 1;
    while (x <= h)
    {
        for (int a = h - x; a > 0; a--)
        {
            printf(" ");
        }
        for (int b = 1; b <= x; b++)
        {
            printf("#");
        }
        printf("\n");
        x++;
    }
}

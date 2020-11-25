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

    //While loop with four for loops nested within for printing two pyramids with a gap in between of them.
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
        for (int c = 0; c < 2; c++)
        {
            printf(" ");
        }
        for (int d = 1; d <= x; d++)
        {
            printf("#");
        }
        printf("\n");
        x++;
    }
}

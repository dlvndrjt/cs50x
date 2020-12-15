#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)  //If input is more than 2 arguments then terminate program.
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int length = strlen(argv[1]);
    char cal[length];
    int x = 0;
    for (int i = 0; i < length; i++)
    {
        cal[i] = argv[1][i];  //Converting a string into an array of chars.

        if (!(isdigit(cal[i])))  //Process of figuring out non digit chars.
        {
            x++;
        }
    }

    if (x > 0)  //If there are other chars than digits then terminate program.
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string text = get_string("plaintext: ");
    
    printf("ciphertext: ");

    int tl = strlen(text);
    int key = atoi(cal);  //Convert array of char into int.
    for (int z = 0; z < tl; z++)  
    {
        if (isupper(text[z]))  //Check to see if a letter is uppercase.
        {
            printf("%c", (((text[z] + key) - 65) % 26) + 65);  //Process of adding key & using wraping formula to encipher plaintext.
        }
        else if (islower(text[z]))  //Check to see if a letter is lowercase.
        {
            printf("%c", (((text[z] + key) - 97) % 26) + 97);  //Process of adding key & using wraping formula to encipher plaintext.
        }
        else  //Rest of chars gets printed out as is.
        {
            printf("%c", text[z]);
        }
    }
    printf("\n");
    return 0;
}

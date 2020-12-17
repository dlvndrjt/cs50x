#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    int y = strlen(argv[1]);
    char array[y];  //For chars of key.
    int z = 0;  //For non-alphabetic chars count.

    for (int x = 0; x < y; x++)
    {
        array[x] = argv[1][x];  //Converting string of cipher-key into an array of char.
        if (!isalpha(array[x])) //For non-alphabetic chars.
        {
            z++;
        }
    }

    int b = 0; //Char being tested against.
    int c = 0; //Count for duplicates. If the count is more than 26 then there are duplicates in the key.
    for (int a = 0; b < 26; a++)  //For finding duplicates.
    {
        if (array[a] == array[b])
        {
            c++;
        }
        if (a == 26)
        {
            a = 0;
            b++;
        }
    }

    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    if (array[y] != array[26])
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    if (z > 0)
    {
        printf("Key must only contain alphabetic characters.");
        return 1;
    }
    if (c > 26)  //26 is the no of times a char in the two similar arrays are similar to another. If c is more than 26 then there are duplicates.
    {
        printf("Key must not contain repeated characters.");
        return 1;
    }

    string pt = get_string("plaintext: ");

    printf("ciphertext: ");

    char DS_Key_Uppercase[26] = { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90 };
    char DS_Key_Lowercase[26] = { 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122 };
    int y2 = 0;
    int z2 = 0;

    for (int x2 = 0; y2 < strlen(pt); x2++)
    {
        if (DS_Key_Uppercase[x2] == (int)pt[y2] || DS_Key_Lowercase[x2] == (int)pt[y2])
        {
            if (isupper(pt[y2]))  //If the char of plaintext is in uppercase.
            {
                printf("%c", toupper(array[x2]));  //Then print the char of key in uppercase.
                z2++;
                y2++;
                x2 = 0;
            }
            else  //Other possibility: (islower(pt[y2]))
            {
                printf("%c", tolower(array[x2]));
                z2++;
                y2++;
                x2 = 0;
            }
        }
        else if (!isalpha(pt[y2]))  //If the char is not an alphabet than print the char of plaintext as is.
        {
            printf("%c", pt[y2]);
            y2++;
            x2 = 0;
        }
    }

    printf("\n");
    return 0;
}

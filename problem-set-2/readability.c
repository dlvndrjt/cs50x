#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");

    int nOc = strlen(text);  //No of characters in text.

    char arrayC[nOc];  //To extract individual characters from text.
    int alpha = 0;  //For number of alphabets in text.
    int words = 1;  //For number of words in text (+1 for the last spaceless word).
    int sentences = 0;  //For number of sentences in text.
    for (int i = 0; i < nOc; i++)
    {
        arrayC[i] = text[i];  //Copying process, rest is for collecting no of alphabets, words, & sentences.
        if (isalpha(arrayC[i]))
        {
            alpha++;
        }
        if (isspace(arrayC[i]))
        {
            words++;
        }
        if (arrayC[i] == '.' || arrayC[i] == '!' || arrayC[i] == '?')
        {
            sentences ++;
        }
    }

    float a1 = alpha;
    float w1 = words;
    float s1 = sentences;
    float L = a1 / w1 * 100;  //Average number of letters.
    float S = s1 / w1 * 100;  //Average number of sentences.
    
    float index0 = 0.0588 * L - 0.296 * S - 15.8;  //Coleman-Liau index calculation.
    
    int index1 = round(index0);  //Rounding index0 and copying the value to int index1 to get rid of decimal.

    if (index1 < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index1 > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index1);
    }
}

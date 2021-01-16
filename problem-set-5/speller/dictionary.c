// Implements a dictionary's functionality.

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table.
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table.
const unsigned int N = (LENGTH + 2) * 'z';

// Hash table.
node *table[N];

// For the size function.
int total_words = 0;

// Returns true if word is in dictionary, else false.
bool check(const char *word)
{
    // Hash word to obtain a hash value.
    int index = hash(word);

    // Access linked list at that index in the hash table.
    node *cursor = table[index];
    while (cursor != NULL)
    {
        // Traverse linked list, looking for the word (strcasecmp).
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number.
unsigned int hash(const char *word)
{
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return (sum % N);
}

// Loads dictionary into memory, returning true if successful, else false.
bool load(const char *dictionary)
{
    // Open dictionary file.
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    //Read strings from file one at a time.
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for each word.
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }

        // Copy word and transfer into new_node->word.
        strcpy(new_node->word, word);  //n->word ??
        new_node->next = NULL;

        // Hash word to obtain a hash value.
        int index = hash(word);

        // Insert node into hash table at that location.
        if (table[index] == NULL)
        {

            table[index] = new_node;
        }
        else
        {
            new_node->next = table[index];
            table[index] = new_node;
        }
        // Increase count for the size funtion.
        total_words++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded.
unsigned int size(void)
{
    return total_words;
}

// Unloads dictionary from memory, returning true if successful, else false.
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *cursor = head;
        node *tmp = head;

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}

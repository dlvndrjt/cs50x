// Work-in-progress.
// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file.
    File *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    //Read strings from file one at a time.
    // Create a new node
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        return false;
    }
    while (fscanf(file, "%s", word) != EOF)
    {
        strcopy(new_node->word, word);  //n->word ??
        new_node->next = NULL;

        int index = hash(word);
        if (table[index] == NULL)
        {
            table[index] = new_node;
        }
        else
        {
            new_node->next = table[index];
            table[index] = new_node;
        }
    }
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}

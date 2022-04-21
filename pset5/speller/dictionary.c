// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"


// Word counter
int i = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    node *cursor = table[hash(word)];

    while(cursor != NULL){
    if((strcasecmp(word, cursor->word)) == 0)
    {
        // printf("Teisingas %s\n", word);
        return true;
    }
    else{
        cursor = cursor->next;
    }
    }
    // printf("Neteisingas %s\n", word);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Load dictionary
    char word[LENGTH + 1];
    FILE *dict = fopen(dictionary, "r");
    // Check if its opened
    if(dict == NULL ){
        printf("nepavyko\n");
        return false;
    }

    for(int l = 0; l < N; l++)
    {
        table[l] = 0;
    }

    node *one;
    while((fscanf(dict, "%s", word )) != EOF)
    {
        if(table[hash(word)] == 0)
        {
            one = malloc(sizeof(node));
            strcpy(one->word, word);
            one->next = NULL;
            table[hash(word)] = one;
        }
        else
        {
            one = malloc(sizeof(node));
            strcpy(one->word, word);
            one->next = table[hash(word)];
            table[hash(word)] = one;
        }
        // strcpy(table[hash(word)]->word, word);
        // strcpy(one->word, word);
        i++;
    }


    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return i;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *cursor = table[0];
    node *tmp = cursor;
    for ( int t = 0; t < N; t++)
    {
    cursor = table[t];
        while(cursor != NULL)
        {
          tmp = cursor;
          cursor = cursor->next;
          free(tmp);
        }
      free(cursor);
    }
    return true;
}

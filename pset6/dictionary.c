/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

//prototypes
#define HASH_SIZE 65536
#define LENGTH 45
int hash_it(const char* needs_hashing);

typedef struct node {
	char word[LENGTH + 1];
	struct node* next;
}
node;
node* hashtable[HASH_SIZE];
int hash_size = -1;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
	char* temp = malloc(sizeof(char) * LENGTH);
	node* new_node = malloc(sizeof(node));
		
    int i;
	for (i = 0; word[i] != '\0'; i++){
    	temp[i] = tolower(word[i]);
    }
    temp[i] = '\0';
    
    int pos = hash_it(temp);
	new_node = hashtable[pos];

	while(new_node != NULL) {
		if(strcmp(new_node->word, temp) == 0) {
				free(temp);
				return true;
		} 
			new_node = new_node->next;
	}
		free(temp);
		free(new_node);
		return false;
}	
	
/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
	FILE* file = fopen(dictionary, "r");
	if(file == NULL) {
		printf("Something went wrong :(\n");
		return false;
	} 
	
	while ((!feof(file))) {
		node* new_node = malloc(sizeof(node));
		fscanf(file, "%s", new_node->word);
		int hash = hash_it(new_node->word);
		if(hashtable[hash] == NULL) {
			new_node->next = NULL;
			hashtable[hash] = new_node;
			hash_size++;
		} else {
			node* prev = malloc(sizeof(node));
			node* curr = malloc(sizeof(node));
			prev = NULL;
			curr = hashtable[hash];
						
			while(curr != NULL && strcmp(curr->word, new_node->word) > 0)  {
				prev = curr;
				curr = curr->next;
			}
			
			if(prev == NULL) {
				hashtable[hash] = new_node;
			} else {
				prev->next = new_node;
			}
		}
	}	
	return true;	
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return hash_size;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    node* pred = NULL;
    node* nextnode = NULL;
    
    for(int i = 0; i < HASH_SIZE; i++){
       nextnode = hashtable[i];
       while(nextnode != NULL) {
           pred = nextnode->next;
           free(nextnode);
           nextnode = pred;
       }
    }
	
	free(pred);
    return true;
}


//Found this hash function on reddit. Posted by Brenda, her husband came up with it.
int hash_it(const char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(needs_hashing); i<n; i++)
        hash = (hash << 2) ^ needs_hashing[i];
    return hash % HASH_SIZE;
}

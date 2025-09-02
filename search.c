#include <ctype.h>
#include "main.h"

void search_database(mainnode **hashtable) 
{
    if(*hashtable == NULL)
    {
        printf("X-------------------X\n");
        printf("Database is empty!!\n");
        printf("X-------------------X\n");
        return;
    }
    char word[20];
    printf("Enter the word to search: ");
    scanf("%s", word);

    int index;
    if (isalpha(word[0])) 
    {
        // Compute index based on the first letter of the search term
        index = tolower(word[0]) % 97;
    } 
    else 
    {
        // Assign index 26 for special characters
        index = 26;
    }

    // Search in the corresponding linked list in the hash table
    mainnode *node = hashtable[index];
    while (node != NULL) 
    {
        char node_data[20];
        strcpy(node_data, node->maindata);

        if (strcmp(node_data, word) == 0) 
        {
            printf("The Word '%s',is present in '%d' files:\n", node->maindata, node->count);

            subnode *sub = node->sublink;
            while (sub != NULL) 
            {
                printf("In file '%s' for '%d' times\n", sub->subdata, sub->count);
                sub = sub->link;
            }
            return; // Word found, exit the function
        }
        node = node->link;
    }

    printf("DATA NOT FOUND\n");
}

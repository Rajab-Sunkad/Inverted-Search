#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

// Function to create the database from the linked list of filenames
int create_database(List_t **head, mainnode **hashtable) 
{
    // Check if hash table is already created
    /*for (int i = 0; i < 27; i++) 
    {
        if (hashtable[i] != NULL) 
        {
            printf("ERROR: Database already created!\n");
            return FAILURE;
        }
    }*/


    List_t *temp = *head;
    //traverse through list
    while (temp != NULL)
    {
        //fetch file name and open in read mode
        FILE *fptr = fopen(temp->str, "r");
        //check if file exists
        if (fptr == NULL) 
        {
            printf("Could not open file %s for reading.\n", temp->str);
            temp = temp->link; // Move to the next file in the list
            continue;
        }
        //define a variable
        char word[20];

        //fetch the word from file and store it to the word array
        while (fscanf(fptr, "%s", word) == 1)
        {
            
            //calculate the index
            int index = tolower(word[0]) % 97;

            //insert the word into the hash table
            // Handle non-alphabetic characters
            if (index >= 26) 
            {
                index = 26; // Handle non-alphabetic characters
            }
            //create main node and subnode
            mainnode *mptr = (mainnode*) malloc(sizeof(mainnode));
            subnode *sptr = (subnode*) malloc(sizeof(subnode));
            
            //check node is created or not
            if (mptr == NULL || sptr == NULL) 
            {
                printf("Memory allocation failed!\n");
                fclose(fptr);
                return FAILURE; // Handle memory allocation failure
            }

            // Initialize the new main node
            create_mainn(mptr, word);
            // Initialize the new sub node
            create_subn(sptr, temp->str);
            
            // Check if hash table index is empty
            if (hashtable[index] == NULL)
            {
                mptr->sublink = sptr;
                hashtable[index] = mptr; // Insert into the hash table
            } 
            else
            {
                // Traverse main nodes
                mainnode *mt = hashtable[index];  //temp ptr to traverse
                mainnode *mprev = NULL;           //prev temp ptr to traverse
                
                while (mt != NULL) 
                {
                    // Check if word matches
                    if (strcmp(mt->maindata, word) == 0) 
                    {
                        // Traverse sub nodes
                        subnode *st = mt->sublink;
                        subnode *sprev = NULL;

                        while (st != NULL) 
                        {
                            // Check if file name matches
                            if (strcmp(st->subdata, temp->str) == 0) 
                            {
                                st->count++;
                                break; // File already counted, break the loop
                            }
                            sprev = st;
                            st = st->link;
                        }
                        
                        // Add new sub node if file not found
                        if (st == NULL) 
                        {
                            create_subn(sptr, temp->str);
                            sprev->link = sptr; // Link the new sub node
                            mt->count++;
                        }
                        free(mptr); // Free memory since we don't need to add a new main node
                        break;
                    }
                    mprev = mt;
                    mt = mt->link;
                }
                
                // Add new main node and sub node if word not found
                if (mt == NULL) 
                {
                    mptr->sublink = sptr;
                    //mptr->link = hashtable[index]; // Link to the existing list
                    //hashtable[index] = mptr; // Insert new main node into the hash table
                    mprev->link = mptr;
                    //mptr->sublink = sptr;
                }
            }
        }
        
        fclose(fptr); // Close the file after processing
        temp = temp->link; // Move to the next file in the list
    }
    
    return SUCCESS; // Return success if all files processed
}

// Function to create main node
mainnode* create_mainn(mainnode *mptr, const char *word) 
{
    mptr->count = 1; // Initialize file count
    strcpy(mptr->maindata, word); // Copy the word into the node
    mptr->link = NULL; // Initialize the link to the next main node
    mptr->sublink = NULL; // Initialize the link to the sub nodes
    
    //return mptr; // Return the initialized main node
}

// Function to create sub node
subnode* create_subn(subnode *sptr, const char *fname) 
{
    sptr->count = 1; // Initialize word count
    strcpy(sptr->subdata, fname); 
    sptr->link = NULL; // Initialize the link to the next sub node
    
    return sptr; // Return the initialized sub node
}
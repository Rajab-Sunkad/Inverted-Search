/*Name: Rajab J S
Project: Inverted Search.
Descrption: Inverted search, also known as inverted indexing, is a technique used in information 
            retrieval systems, such as search engines, to efficiently retrieve documents or records 
            that contain specific keywords or phrases.

            In a traditional search approach, the system would scan through each document or record to
            find matches for the search query. This approach can be time-consuming and inefficient, 
            especially when dealing with large datasets.

            Inverted search, on the other hand, uses an inverted index data structure to store the 
            relationships between keywords or phrases and the documents or records that contain them.

            The inverted index is essentially a mapping of keywords to documents, allowing the 
            system to quickly look up which documents contain a specific keyword or phrase.

*/
#include <stdio.h>
#include "main.h"
List_t *f_head_init = NULL;
int main(int argc, char *argv[]) 
{
    List_t *head = NULL;
    mainnode *hashtable[27] = {NULL};

    if (argc <= 1) 
    {
        printf("Please enter the valid file formats!\n");
        printf("Usage: file1.txt file2.txt file3.txt........\n");
        return FAILURE;
    } 
    else 
    {
        //check whether  the input is valid or not
        if (validate(argc, argv, &head) == FAILURE) 
        {
            return FAILURE;
        }
    }
    int choice;
    do 
    {
        printf("1. Create database\n2. Display database\n3. Search database\n4. Save database\n5. Update database\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
            List_t *temp = head;
            List_t *prev = NULL;
            while (temp != NULL) 
            {
                // Check if file already exists in hash table
                for (int i = 0; i < 27; i++) 
                {
                    mainnode *node = hashtable[i];
                    while (node != NULL) 
                    {
                        subnode *sub = node->sublink;
                        while (sub != NULL) 
                        {
                            if (strcmp(sub->subdata, temp->str) == 0) 
                            {
                                printf("ERROR: File %s already exists in database!\n", temp->str);
                                prev = temp->link;
                                head = temp->link;
                                free(temp);
                                break;
                            }
                            sub = sub->link;
                        }
                        node = node->link;
                    }
                }
                temp = temp->link;
                //head = temp;
            }
                // Call create database function 
                if(create_database(&head,hashtable) == SUCCESS)
                {
                    printf("Database for the given file is created successfully! \n");
                }
                else
                {
                    printf("Database is not created! \n");
                }
                break;
            case 2:
                // Call display database function
                display(hashtable); 
                break;
            case 3:
                // Call search database function 
                search_database(hashtable);
                break;
            case 4:
                // Call save database function 
                save_database(hashtable);
                break;
            case 5:
                // Call update database function
                //update_database(hashtable,&head); 
                update_database(&head,hashtable);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } 
    while (choice != 6); 
    return SUCCESS;
}

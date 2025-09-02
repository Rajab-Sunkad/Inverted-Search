#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int update_database(List_t **head,mainnode **hash_table) 
{
    // Check if hash table is empty
    List_t *temp1 = *head;
    for (int i = 0; i < 27; i++) 
    {
        if (hash_table[i] != NULL) 
        {
            printf("ERROR: Hash table is not empty, Unable to update database\n");
            return FAILURE;
        }
    }

    char back_up_file_name[20];
    printf("------------------------------------\n");
    printf("INFO: Enter the backup file name: ");
    scanf("%s", back_up_file_name);

char *ptr = strstr(back_up_file_name, ".txt");
    if(ptr == NULL) 
    {
        printf("Warning: Invalid Extension for file %s\n", back_up_file_name);
        return FAILURE;
    }

    FILE *fptr = fopen(back_up_file_name, "r");
    if (fptr == NULL) 
    {
        printf("ERROR: Unable to open %s file\n", back_up_file_name);
        return FAILURE;
    }
    int result = process_backup_entry(fptr, hash_table);
    fclose(fptr);
    return result;
}

int process_backup_entry(FILE *fptr, mainnode **hash_table) 
{
    char arr[50];
    int index = 0;
    char word[50];
    int file_count = 0;
    char file_name[50];
    int word_count = 0;
    //List_t *temp=*head;

    while (fscanf(fptr, "%s", arr) != EOF) 
    {
        if (arr[0] == '#') 
        {
            // Parse the entry
            index = atoi(strtok(&arr[1], ";"));
            strcpy(word, strtok(NULL, ";"));
            file_count = atoi(strtok(NULL, ";"));

            mainnode *main_n = malloc(sizeof(mainnode));
            if (main_n == NULL)
                return FAILURE;

            main_n->count = file_count;
            strcpy(main_n->maindata, word);
            main_n->link = NULL;
            main_n->sublink = NULL;

            // Process the sub nodes
            subnode *sub = malloc(sizeof(subnode));
            if (sub == NULL)
                return FAILURE;

            strcpy(sub->subdata, strtok(NULL, ";"));
            sub->count = atoi(strtok(NULL, ";"));
            sub->link = NULL;
            main_n->sublink = sub;

            subnode *temp = sub;
            while (--file_count) 
            {
                subnode *sub = malloc(sizeof(subnode));
                if (sub == NULL)
                    return FAILURE;
                strcpy(sub->subdata, strtok(NULL, ";"));
                sub->count = atoi(strtok(NULL, ";"));
                sub->link = NULL;
                temp->link = sub;
                temp = sub;
            }

            // Insert into hash table
            if (hash_table[index] == NULL) 
            {
                hash_table[index] = main_n;
            } 
            else 
            {
                mainnode *temp = hash_table[index];
                while (temp->link != NULL) 
                {
                    temp = temp->link;
                }
                temp->link = main_n;
            }
        } 
		else 
		{
            printf("Invalid file format\n");
            return FAILURE;
        }
    }
    printf("------------------------------------\n");
    printf("INFO: Database updated successfully\n");
    printf("------------------------------------\n");
    return SUCCESS;
}
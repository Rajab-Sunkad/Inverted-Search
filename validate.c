#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validate(int argc, char *argv[], List_t **head) 
{
    int i;
    int flag1 = 0;

    for (i = 1; i < argc; i++) 
    { 
        char *ptr = strstr(argv[i], ".txt");

        if(ptr == NULL) 
        {
            printf("Warning: Invalid Extension for file %s\n", argv[i]);
            continue;
        }
        // File error handling
        FILE *fptr = fopen(argv[i], "r");
        if (fptr == NULL) 
        {
            printf("File %s does not exist!\n", argv[i]);
            continue; 
        }
        

        // Check for contents of file
        fseek(fptr, 0, SEEK_END);
        if (ftell(fptr) == 0) 
        {
            printf("INFO: %s is Empty!!\n", argv[i]);
            fclose(fptr);
            continue;
        }

        // Insert file to list
        List_t *new = malloc(sizeof(List_t));
        if (new == NULL) 
        {
            printf("Memory allocation failed! \n");
            fclose(fptr);
            return FAILURE;
        }
        new->link = NULL;
        strcpy(new->str, argv[i]);

        // If the list is empty
        if (*head == NULL) 
        {
            *head = new;
            printf("INFO: List created for %s\n", argv[i]);
            flag1 = 1;
            fclose(fptr);
            continue;
        }

        // Check for duplicates
        List_t *temp = *head;
        int flag2 = 0;
        while (temp->link != NULL) 
        {
            if (strcmp(temp->str, argv[i]) == 0) 
            {
                printf("INFO: File %s already exists in the list!\n", argv[i]);
                flag2 = 1;
                break;
            }
            temp = temp->link;
        }
        // Check the last node
        if (strcmp(temp->str, argv[i]) == 0) 
        {
            printf("INFO: File %s already exists in the list!\n", argv[i]);
            flag2 = 1;
        }

        if (flag2) 
        {
            printf("Warning: %s duplicate found!!\n", argv[i]);
            free(new); // Free allocated memory if duplicate
        } 
        else 
        {
            temp->link = new;
            printf("INFO: List created for %s\n", argv[i]);
            flag1 = 1;
        }

        fclose(fptr);
    }
    if(flag1)
    {
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

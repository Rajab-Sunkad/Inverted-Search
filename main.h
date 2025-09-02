#ifndef MAIN_H
#define MAIN_H

#define SUCCESS 0
#define FAILURE -1
#define DATA_NOT_FOUND


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



//linked list structure
typedef struct node 
{
    char str[30];
    struct node *link;
} List_t;
//subnode structure
typedef struct subnode
{
    int count;
    char subdata[20];
    struct subnode *link;
}subnode;

//structure for the main node
typedef struct mainnode
{
    int count;
    char maindata[20];
    struct mainnode *link;
    subnode *sublink;
}mainnode;


// Function prototypes
int validate(int argc, char *argv[], List_t **head);
// Add other function prototypes as needed
mainnode* create_mainn(mainnode *mptr, const char *word);
subnode* create_subn(subnode *sptr, const char *fname);
int create_database(List_t **head, mainnode **hashtable);
void display(mainnode **hashtable);
void search_database(mainnode **hashtable);
int save_database(mainnode **hashtable);
int update_database(List_t **head,mainnode **hash_table);
int process_backup_entry(FILE *fptr, mainnode **hash_table);
int file_exists_in_hashtable(const char *filename, mainnode **hashtable);

#endif 

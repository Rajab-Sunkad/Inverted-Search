#include <stdio.h>
#include "main.h"

void display(mainnode **hashtable)
 {
    if(*hashtable == NULL)
    {   
        printf("X-------------------X\n");
        printf("Database is empty!!\n");
        printf("X-------------------X\n");
        return;
    }
    printf("..................................................................................................\n");
    printf("Index\tWord\t\tFile_Count\tFile_Name\tWord_Count\tFile_Name\tWord_Count\n");
    printf("..................................................................................................\n");

    for (int i = 0; i <= 26; i++) 
    {
        mainnode *mptr = hashtable[i];
        
        while (mptr != NULL)
        {
            subnode *sptr = mptr->sublink;
            
            printf("%-6d %-20s %-12d", i, mptr->maindata, mptr->count);
            
            while (sptr != NULL) 
            {
                printf("%-19s %-13d", sptr->subdata, sptr->count);
                sptr = sptr->link;
            }
            
            printf("\n");
            mptr = mptr->link;
        }
    }
    printf("..................................................................................................\n");

}

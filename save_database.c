#include "main.h"
int save_database(mainnode **hashtable)
{
    if(*hashtable == NULL)
    {
        printf("-----------------------------------------\n");
        printf("Database not saved!!, Hashtable is empty.\n");
        printf("-----------------------------------------\n");
        return FAILURE;
    }
    char filename[20];
    printf("Enter filename to save database: ");
    scanf("%s", filename);
    char *ptr = strstr(filename,".txt");
    if(ptr == NULL)
    {
        strcat(filename,".txt");
    }
    FILE *fp = fopen(filename, "w");
    if(fp == NULL)
    {
        printf("\nError opening file!!\n\n");
        return FAILURE;
    }
    for (int i = 0; i <= 26; i++) 
    {
        mainnode *mptr = hashtable[i];
        
        while (mptr != NULL)
        {
            subnode *sptr = mptr->sublink;
            fprintf(fp,"#%d;%s;%d",i,mptr->maindata,mptr->count);
            while(sptr!=NULL)
		    {
                fprintf(fp,";%s;%d",sptr->subdata,sptr->count);  
			    sptr=sptr->link;
		    }
		    fprintf(fp,"#\n");
		    mptr=mptr->link;
        }
    }
return SUCCESS;
}

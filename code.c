#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "code.h"
#include "trie.h"

void coding(FILE* input,FILE* output)
{
    dictionary  *node=NULL,
                 *temp=NULL,
                  *check=NULL;
    node=start();
    temp=node;
    uint16_t j=1;
    uint8_t buffer;
    while(!feof(input))
    {
        if(j==UINT16_MAX)
        {
            clear_dictionary(node);
            j=1;
            node=start();
            temp=node;
        }
        fread(&buffer,sizeof(uint8_t),1,input);
        check=find_ch(temp,buffer);
        if (check==NULL)
        {
            push(temp,j,buffer);
            fwrite(&(temp->key),sizeof(uint16_t),1,output);
            fwrite(&(temp->leaf->ch),sizeof(uint8_t),1,output);
            ++j;
            temp=node;
        }
        else
        {
            temp=check;
        }
    }
    clear_dictionary(node);
    fclose(input);
    fclose(output);
}

void decode(FILE* input, FILE* output)
{
    dictionary  *node=NULL;
    dictionary  *temp=NULL,
                *print=NULL;
    node=start();
    dictionary **pp_dictionary=(dictionary**)malloc(sizeof(dictionary*)*UINT16_MAX);
    pp_dictionary[0]=node;
    uint16_t j=1;
    uint16_t buffer_16;
    uint8_t buffer_8;
    while(!feof(input))
    {
        if(j==UINT16_MAX)
        {
            j=1;
            int i=0;
            for(i=0;i<UINT16_MAX;++i)
                {
                    free(pp_dictionary[i]);
                    pp_dictionary[i]=NULL;
                }
            node=start();
            pp_dictionary[0]=node;
        }
        fread(&buffer_16,sizeof(uint16_t),1,input);
        fread(&buffer_8,sizeof(uint8_t),1,input);
        temp=pp_dictionary[buffer_16];
        print=push_decode(temp,j,buffer_8);
        pp_dictionary[j]=print;
        set_to_print(print);
        ++j;
        print_lz_d(node,output);
    }
    int i;
    for(i=0;i<UINT16_MAX;++i)
            { if(pp_dictionary[i])
                 free(pp_dictionary[i]);}
    free(pp_dictionary);
    fclose(input);
    fclose(output);
}

void print_lz_d(dictionary* head,FILE* output)
{
    dictionary* temp=head;
     while(temp->child)
        {
            fwrite(&(temp->child->ch),sizeof(uint8_t),1,output);
            temp=temp->child;
        }
}




/*void wypisz(dictionary*head)
{
    if (head->next!=NULL) wypisz(head->next);
    if (head->leaf!=NULL) wypisz(head->leaf);
    printf("wypisuje [%d] %d \n",head->key,head->ch);
}*/

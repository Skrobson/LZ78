#include "trie.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void push(dictionary* head,uint16_t key,uint8_t ch)
{
    dictionary* tmp=(dictionary*)malloc(sizeof (dictionary));
    tmp->key=key;
    tmp->ch=ch;
    tmp->leaf=NULL;
    tmp->child=NULL;
    tmp->next=head->leaf;
    tmp->parent=head;
    head->leaf=tmp;


}

dictionary* push_decode(dictionary* head,uint16_t key,uint8_t ch)
{
    dictionary* tmp=(dictionary*)malloc(sizeof (dictionary));
    tmp->key=key;
    tmp->ch=ch;
    tmp->leaf=NULL;
    tmp->child=NULL;
    if(head->key)
        tmp->next=head->leaf;
    tmp->parent=head;
    head->leaf=tmp;
    return tmp;

}


dictionary* start()
{
    dictionary* trie=(dictionary*)malloc(sizeof (dictionary));
    trie->ch=0;
    trie->key=0;
    trie->leaf=NULL;
    trie->next=NULL;
    trie->parent=NULL;
    trie->child=NULL;
    return trie;
}

dictionary* find_ch(dictionary* head,uint8_t ch)
{
    if (head->leaf==NULL) return NULL;
    dictionary* tmp=head->leaf;
    do
    {
        if (tmp->ch==ch) return tmp;
        else tmp=tmp->next;
    }
    while(tmp!=NULL);
    return tmp;
}



void clear_dictionary(dictionary* head)
{
    dictionary* tmp=head;
    if (tmp->next!=NULL) clear_dictionary(tmp->next);
    if (tmp->leaf!=NULL) clear_dictionary(tmp->leaf);
    tmp->next=NULL;
    tmp->leaf=NULL;
    free(tmp);
    tmp=NULL;
}

void set_to_print(dictionary* print)
{
    do
    {
        print->parent->child=print;
        print=print->parent;
    }
    while(print->parent!=NULL);
}



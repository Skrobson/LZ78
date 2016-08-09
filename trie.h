#ifndef trie_h
#define trie_h

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct dictionary
{
    uint8_t ch;
    uint16_t key;
    struct dictionary* leaf;
    struct dictionary* next;
    struct dictionary* parent;
    struct dictionary* child;

}dictionary;

void push(dictionary* head,uint16_t key, uint8_t ch);/*OK*/

dictionary* push_decode(dictionary* head,uint16_t key, uint8_t ch);

dictionary* find_ch(dictionary* head,uint8_t ch);/*OK*/

dictionary* find_key(dictionary* head,uint16_t ch);

void clear_dictionary(dictionary* head);

dictionary* start();/*OK*/

void set_to_print(dictionary* print);
#endif

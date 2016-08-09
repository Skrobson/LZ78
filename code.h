#ifndef code_h
#define code_h
#include "files.h"
#include "trie.h"
#include <stdint.h>

void coding(FILE* input,FILE* output );
void decode(FILE* input,FILE* output);
/*void wypisz(dictionary*head);*/
void print_lz_d(dictionary* head,FILE* output);




#endif

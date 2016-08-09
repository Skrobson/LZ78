#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "files.h"

FILE* open_i(char* input)
{
    const short size=100;
    FILE* f;
    char *new_in;
    f=fopen(input,"rb");
    while(!f)
    {
        new_in=malloc(sizeof(char)*size);
        printf("\nPLIK WEJSCIOWY NIE ISTNIEJE\n");
        printf("Podaj plik jeszcze raz\n:");
        gets(new_in);
        f=fopen(new_in,"rb");
        free(new_in);
    }

    return f;
}
FILE* open_o( char* output)
{
    const short size=100;
    FILE* f, *o;
    char *new_in;
    char *temp_name;
    temp_name=malloc(sizeof(char)*size);
    strcpy(temp_name,output);
    f=fopen(output,"rb");

    while(f)
    {
        char a;
        printf("\nPodany plik istnieje, czy chcesz go nadpisac?\n(Y/N)?: ");
        scanf("%c",&a);
        if ((a=='n'||a=='N'))
        {
            fclose(f);
            new_in=malloc(sizeof(char)*size);
            printf("Podaj plik jeszcze raz\n:");/*poprawic, moze funkcja sprawdzjaca*/
            fflush(stdin);
            gets(new_in);
            f=fopen(new_in,"rb");
            strcpy(temp_name,new_in);
            free(new_in);
        }
        else
        {
            fclose(f);
            f=NULL;
        }

    }
     if(!f)
    {
        o=fopen(temp_name,"wb");
    }
    free(temp_name);
    return o;
}





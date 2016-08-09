#include "files.h"
#include "code.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

void help();
int main(int argc, char** argv)

{
    const unsigned max_arg=6;
    char * input=NULL,
                 * output=NULL;
    FILE *in,*out;
    int prog=0,opt=0;
    if(argc!=max_arg) prog='h';
    if(argc==max_arg)
    {
    while((opt=getopt(argc,argv,":o:f:cd"))!=-1)
    {
        switch(opt)
        {
        case 'c':
            if(prog)prog='h';
            else prog='c';
            break;
        case 'd':
            if(prog) prog='h';
            else prog='d';
            break;
        case 'f':
            input=optarg;
            break;
        case 'o':
            output=optarg;
            break;
        case ':':
            printf("brakuje elememntu -%c",optopt);
        case '?':
        default:
        help();
            break;

        }
    }
    }
    switch(prog)
    {
    case 'c':

        in=open_i(input);
        out=open_o(output);
        printf("%s-->%s",input,output);
        coding(in,out);
        printf("\nKompresja zakonczona sukcesem");
        break;
    case 'd':
        in=open_i(input);
        if(!in)
            {
                printf("nie udalo sie otworzyc pliku wejsciowego");
            }
        out=open_o(output);
        if(!out)
        {
            printf("Nie udalo sie otworzyc pliku wyjsciowego");
        }
        printf("%s-->%s",output,input);
        decode(in,out);
        printf("\nDekompresja zakonczona sukcesem\n");
        break;
    case 'h':
    default:
        help();
        break;

    }

    return 0;
}
void help()
{
    printf("\n\tkomprezja algorytmem LZ78\n"
           "-c kompresja\n"
           "-d dekompresja\n"
           "-f plik wejsciowy\n"
           "-o plik wyjsciowy");


}



#include <stdio.h>
#include "lexer.h"

int main(int argc, char *argv[])
{
    FILE *fp;

    if(argc != 2)
    {
        printf("Usage: ./a.out <filename.c>\n");
        return 1;
    }

    fp = fopen(argv[1], "r");

    if(fp == NULL)
    {
        printf("ERROR: Unable to open file\n");
        return 1;
    }

    printf("Open : %s : Success\n", argv[1]);
    printf("Parsing : %s : Started\n\n", argv[1]);

    parse_file(fp);

    printf("\nParsing : %s : Done\n", argv[1]);

    fclose(fp);

    return 0;
}
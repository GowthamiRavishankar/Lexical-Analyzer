#include <string.h>
#include "lexer.h"

char *keywords[] =
{
    "auto","break","case","char","const","continue",
    "default","do","double","else","enum","extern",
    "float","for","goto","if","int","long",
    "register","return","short","signed","sizeof",
    "static","struct","switch","typedef","union",
    "unsigned","void","volatile","while"
};

int is_keyword(char *str)
{
    int size = sizeof(keywords) / sizeof(keywords[0]);

    for(int i = 0; i < size; i++)
    {
        if(strcmp(str, keywords[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"

int is_operator(char ch)
{
    char operators[] = "+-*/%=<>!&|^";

    for(int i = 0; operators[i] != '\0'; i++)
    {
        if(ch == operators[i])
        {
            return 1;
        }
    }

    return 0;
}

int is_special_symbol(char ch)
{
    char symbols[] = "(){}[];,:";

    for(int i = 0; symbols[i] != '\0'; i++)
    {
        if(ch == symbols[i])
        {
            return 1;
        }
    }

    return 0;
}

void parse_file(FILE *fp)
{
    char ch;

    while((ch = fgetc(fp)) != EOF)
    {
        /* Ignore spaces */
        if(isspace(ch))
        {
            continue;
        }

        /* Identifier or Keyword */
        if(isalpha(ch) || ch == '_')
        {
            char buffer[100];
            int i = 0;

            buffer[i++] = ch;

            while((ch = fgetc(fp)) != EOF &&
                  (isalnum(ch) || ch == '_'))
            {
                buffer[i++] = ch;
            }

            buffer[i] = '\0';

            ungetc(ch, fp);

            if(is_keyword(buffer))
            {
                printf("Keyword\t\t: %s\n", buffer);
            }
            else
            {
                printf("Identifier\t: %s\n", buffer);
            }
        }

        /* Number Literal */
        else if(isdigit(ch))
        {
            char buffer[100];
            int i = 0;
            int dot = 0;

            buffer[i++] = ch;

            while((ch = fgetc(fp)) != EOF &&
                  (isdigit(ch) || ch == '.'))
            {
                if(ch == '.')
                {
                    dot = 1;
                }

                buffer[i++] = ch;
            }

            buffer[i] = '\0';

            ungetc(ch, fp);

            if(dot)
            {
                printf("Float Literal\t: %s\n", buffer);
            }
            else
            {
                printf("Integer Literal: %s\n", buffer);
            }
        }

        /* String Literal */
        else if(ch == '"')
        {
            char buffer[200];
            int i = 0;

            buffer[i++] = ch;

            while((ch = fgetc(fp)) != EOF && ch != '"')
            {
                buffer[i++] = ch;
            }

            buffer[i++] = '"';
            buffer[i] = '\0';

            printf("String Literal\t: %s\n", buffer);
        }

        /* Character Literal */
        else if(ch == '\'')
        {
            char buffer[20];
            int i = 0;

            buffer[i++] = ch;

            while((ch = fgetc(fp)) != EOF && ch != '\'')
            {
                buffer[i++] = ch;
            }

            buffer[i++] = '\'';
            buffer[i] = '\0';

            printf("Char Literal\t: %s\n", buffer);
        }

        /* Operators */
        else if(is_operator(ch))
        {
            printf("Operator\t: %c\n", ch);
        }

        /* Special Symbols */
        else if(is_special_symbol(ch))
        {
            printf("Special Symbol\t: %c\n", ch);
        }
    }
}
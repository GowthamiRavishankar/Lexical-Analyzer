#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>

void parse_file(FILE *fp);

int is_keyword(char *str);
int is_operator(char ch);
int is_special_symbol(char ch);

#endif
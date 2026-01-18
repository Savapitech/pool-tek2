/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parse_alias
*/

#include <string.h>
#include <stdio.h>

#include "./string.h"

void print(const string_t *this)
{
    if (this->str == NULL)
        return;
    printf("%s", this->str);
}

char *data(const string_t *this)
{
    return this->str;
}

void clear(string_t *this)
{
    if (this->str == NULL)
        return;
    memset(this->str, 0, strlen(this->str));
}

void assign(string_t *this, const char *str)
{
    free(this->str);
    this->str = strdup(str);
    if (this->str == NULL)
        abort();
}

void append(string_t *this, const char *str)
{
    if (this->str == NULL)
        return;
    this->str = realloc(this->str, strlen(this->str) + strlen(str) + 1);
    if (this->str == NULL)
        abort();
    strcat(this->str, str);
}

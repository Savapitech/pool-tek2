/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parse_alias
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "./string.h"

size_t length(const string_t *this)
{
    if (this->str == NULL)
        return 0;
    return strlen(this->str);
}

char at_fnc(const string_t *this, size_t pos)
{
    if (this->str == NULL || pos > strlen(this->str) - 1 || !this->str[0])
        return -1;
    return this->str[pos];
}

bool empty(const string_t *this)
{
    if (this->str == NULL)
        return false;
    return !strlen(this->str);
}

void string_init(string_t *this, const char *s)
{
    this->str = strdup(s);
    if (this->str == NULL)
        abort();
    this->empty = &empty;
    this->length = &length;
    this->at = &at_fnc;
    this->print = &print;
    this->data = &data;
    this->clear = &clear;
    this->assign = &assign;
    this->append = &append;
}

void string_destroy(string_t *this)
{
    free(this->str);
}

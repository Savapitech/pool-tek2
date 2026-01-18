/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parse_alias
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "./list.h"

void apply(list_t *this, void *(*function)(void *))
{
    if (this->list == NULL)
        return;
    for (size_t i = 0; i < this->sz; i++)
        this->list[i] = function(this->list[i]);
}

bool set(list_t *this, size_t index, void *value)
{
    if (this->list == NULL || index >= this->sz)
        return false;
    this->list[index] = value;
    return true;
}

void *get(list_t *this, size_t index)
{
    if (this->list == NULL || index >= this->sz)
        return NULL;
    return this->list[index];
}

void clear(list_t *this)
{
    if (this->list == NULL)
        return;
    for (size_t i = 0; i < DEFAULT_CAP; i++)
        this->list[i] = NULL;
    this->sz = 0;
}

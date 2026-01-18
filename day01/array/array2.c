/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parse_alias
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "./array.h"

void apply(array_t *this, void *(*function)(void *))
{
    if (this->array == NULL)
        return;
    for (size_t i = 0; i < this->sz; i++)
        this->array[i] = function(this->array[i]);
}

bool set(array_t *this, size_t index, void *value)
{
    if (!this->sz || index >= this->sz)
        return false;
    this->array[index] = value;
    return true;
}

void *get(array_t *this, size_t index)
{
    if (this->array == NULL || !this->sz || index >= this->sz)
        return NULL;
    return this->array[index];
}

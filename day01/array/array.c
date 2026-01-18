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

void resize(array_t *this, size_t size)
{
    if (this->array == NULL)
        return;
    if (size < this->sz) {
        for (size_t i = size; i < this->sz; i++)
            this->array[i] = NULL;
        this->sz = size;
        return;
    }
    this->array = realloc(this->array, size * sizeof(void *));
    if (this->array == NULL)
        abort();
    for (size_t i = this->sz; i < size; i++)
        this->array[i] = NULL;
    this->sz = size;
    this->cap = size;
}

size_t size(const array_t *this)
{
    return this->sz;
}

bool empty(const array_t *this)
{
    return !this->sz;
}

void array_init(array_t *this, size_t sz)
{
    this->array = malloc(sizeof *this->array * sz);
    if (this->array == NULL)
        abort();
    for (size_t i = 0; i < sz; i++)
        this->array[i] = NULL;
    this->sz = sz;
    this->cap = sz;
    this->empty = &empty;
    this->size = &size;
    this->resize = &resize;
    this->apply = &apply;
    this->set = &set;
    this->get = &get;
}

void array_destroy(array_t *this)
{
    free(this->array);
}

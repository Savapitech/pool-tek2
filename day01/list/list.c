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

bool ensure_cap(list_t *this)
{
    if (this->sz > this->cap - 1)
        this->list = realloc(this->list, sizeof *this->list * this->cap << 1);
    if (this->list == NULL)
        abort();
    this->cap <<= 1;
    return true;
}

size_t size(const list_t *this)
{
    return this->sz;
}

bool empty(const list_t *this)
{
    return !this->sz;
}

void list_init(list_t *this)
{
    this->list = malloc(DEFAULT_CAP * sizeof *(this->list));
    if (this->list == NULL)
        abort();
    for (size_t i = 0; i < DEFAULT_CAP; i++)
        this->list[i] = NULL;
    this->sz = 0;
    this->cap = DEFAULT_CAP;
    this->empty = &empty;
    this->size = &size;
    this->apply = &apply;
    this->get = &get;
    this->set = &set;
    this->push_front = &push_front;
    this->push_back = &push_back;
    this->pop_front = &pop_front;
    this->pop_back = &pop_back;
    this->clear = &clear;
}

void list_destroy(list_t *this)
{
    free(this->list);
}

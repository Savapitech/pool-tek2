/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parse_alias
*/

#include <string.h>

#include "./list.h"

void push_front(list_t *this, void *value)
{
    if (this->list == NULL)
        return;
    this->sz++;
    if (!ensure_cap(this))
        return;
    if (this->sz > 1)
        memmove(this->list + 1, this->list,
            sizeof *this->list * (this->sz - 1));
    *this->list = value;
}

void push_back(list_t *this, void *value)
{
    if (this->list == NULL)
        return;
    this->sz++;
    if (!ensure_cap(this))
        return;
    this->list[this->sz - 1] = value;
}

void pop_front(list_t *this)
{
    if (this->list == NULL)
        return;
    memmove(this->list, this->list + 1, sizeof *this->list * (this->sz - 1));
    this->sz--;
}

void pop_back(list_t *this)
{
    if (this->list == NULL)
        return;
    this->list[this->sz - 1] = NULL;
    this->sz--;
}

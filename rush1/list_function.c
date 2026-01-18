  /*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include "list.h"
#include <stdlib.h>

list_t *create_list(void)
{
    list_t *list = malloc(sizeof(list_t));

    list->head = NULL;
    list->tail = NULL;
    list->lsize = 0;
    return list;
}

static node_t *fill_pushback(node_t *node, void *data, node_t *prev)
{
    node->prev = prev;
    node->data = data;
    node->next = NULL;
    return node;
}

void lpushback(list_t *list, void *data)
{
    node_t *to_add = malloc(sizeof(node_t));

    if (!list || !data)
        return;
    to_add = fill_pushback(to_add, data, list->tail);
    if (list->tail)
        list->tail->next = to_add;
    list->tail = to_add;
    if (!list->head)
        list->head = to_add;
    list->lsize++;
}


static node_t *fill_pushfront(node_t *node, void *data, node_t *next)
{
    node->next = next;
    node->data = data;
    node->prev = NULL;
    return node;
}

void lpushfront(list_t *list, void *data)
{
    node_t *to_add = malloc(sizeof(node_t));

    if (!list || !data)
        return;
    to_add = fill_pushfront(to_add, data, list->head);
    if (list->head)
        list->head->prev = to_add;
    list->head = to_add;
    if (!list->tail)
        list->tail = to_add;
    list->lsize++;
}

void lpopback(list_t *list)
{
    node_t *last;

    if (!list || !list->tail)
        return;
    last = list->tail;
    if (list->head == list->tail){
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    free(last);
    list->lsize--;
}

void lpopfront(list_t *list)
{
    node_t *first;

    if (!list || !list->head)
        return;
    first = list->head;
    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    free(first);
    list->lsize--;
}

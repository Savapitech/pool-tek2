
/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** Exercice 05
*/

#pragma once

#include "container_ex06.h"

typedef struct node_s node_t;

typedef struct node_s {
  Object *data;
  node_t *prev;
  node_t *next;
} node_t;

typedef struct list_s {
  node_t *head;
  node_t *tail;
  size_t lsize;
} list_t;

list_t *create_list(void);
void lpushfront(list_t *list, void *data);
void lpushback(list_t *list, void *data);
void lpopfront(list_t *list);
void lpopback(list_t *list);

extern const Class  *List;

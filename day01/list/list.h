/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parse_alias
*/

#ifndef STRING_H
    #define STRING_H
    #define DEFAULT_CAP 10

    #include <stdlib.h>
    #include <stdbool.h>

typedef struct list_s list_t;

typedef struct list_s {
    bool (*empty)(const list_t *);
    size_t (*size)(const list_t *);
    void (*apply)(list_t *, void *(*function)(void *));
    bool (*set)(list_t *, size_t index, void *value);
    void *(*get)(list_t *, size_t index);
    void (*push_front)(list_t *, void *);
    void (*push_back)(list_t *, void *);
    void (*pop_front)(list_t *);
    void (*pop_back)(list_t *);
    void (*clear)(list_t *);
    void **list;
    size_t sz;
    size_t cap;
} list_t;


void list_init(list_t *);
void list_destroy(list_t *);

void apply(list_t *, void *(*function)(void *));
void *get(list_t *, size_t index);
bool set(list_t *, size_t index, void *value);
void push_front(list_t *, void *value);
void push_back(list_t *, void *value);
void pop_front(list_t *);
void pop_back(list_t *);
void clear(list_t *);

bool ensure_cap(list_t *);
#endif

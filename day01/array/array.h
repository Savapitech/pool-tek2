/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parse_alias
*/

#ifndef STRING_H
    #define STRING_H

    #include <stdlib.h>
    #include <stdbool.h>

typedef struct array_s array_t;

typedef struct array_s {
    bool (*empty)(const array_t *);
    size_t (*size)(const array_t *);
    void (*resize)(array_t *, size_t);
    void (*apply)(array_t *, void *(*function)(void *));
    bool (*set)(array_t *, size_t index, void *value);
    void *(*get)(array_t *, size_t index);
    void **array;
    size_t sz;
    size_t cap;
} array_t;


void array_init(array_t *, size_t size);
void array_destroy(array_t *);

void apply(array_t *, void *(*function)(void *));
void *get(array_t *, size_t index);
bool set(array_t *, size_t index, void *value);
#endif

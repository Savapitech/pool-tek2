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

typedef struct string_s string_t;

typedef struct string_s {
    bool (*empty)(const string_t *);
    size_t (*length)(const string_t *);
    char (*at)(const string_t *, size_t pos);
    void (*print)(const string_t *);
    char *(*data)(const string_t *);
    void (*clear)(string_t *);
    void (*assign)(string_t *, const char *str);
    void (*append)(string_t *, const char *str);
    char *str;
} string_t;


void string_init(string_t *, const char *s);
void string_destroy(string_t *);

size_t length(const string_t *);
char at_fnc(const string_t *, size_t pos);
void print(const string_t *);
char *data(const string_t *);
void clear(string_t *);
void assign(string_t *, const char *str);
void append(string_t *, const char *str);
#endif

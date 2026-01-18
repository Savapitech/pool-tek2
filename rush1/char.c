/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdarg.h>
#include <stdio.h>

#include "char.h"
#include "object.h"
#include "new.h"

typedef struct
{
    Class   base;
    char     x;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

char *Char_str(CharClass *this)
{
    char *str;

    if (!asprintf(&str, "<%s (%c)>", ((Class *)this)->__name__, this->x))
        raise("Asprintf error");
    return str;
}

Object *Char_add(CharClass *this, CharClass *other)
{
    char xx;

    if (this == NULL || other == NULL)
        return NULL;
    xx = this->x + other->x;
    return new(Char, xx);
}

Object *Char_sub(CharClass *this, CharClass *other)
{
    char xx;

    if (this == NULL || other == NULL)
        return NULL;
    xx = this->x - other->x;
    return new(Char, xx);
}

Object *Char_mul(CharClass *this, CharClass *other)
{
    char xx;

    if (this == NULL || other == NULL)
        return NULL;
    xx = this->x * other->x;
    return new(Char, xx);
}

Object *Char_div(CharClass *this, CharClass *other)
{
    char xx;

    if (this == NULL || other == NULL || other->x == 0)
        return NULL;
    xx = this->x / other->x;
    return new(Char, xx);
}

bool Char_eq(CharClass *this, CharClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    return this->x == other->x;
}


bool Char_gt(CharClass *this, CharClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    return this->x > other->x;
}

bool Char_lt(CharClass *this, CharClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    return this->x < other->x;
}

// Create additional functions here

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(_description),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .x = 0
};

const Class   *Char = (const Class *)&_description;

/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdarg.h>
#include <stdio.h>
#include "int.h"
#include "object.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
}

char *Int_str(IntClass *this)
{
    char *str;

    if (!asprintf(&str, "<%s (%d)>", ((Class *)this)->__name__, this->x))
        raise("Asprintf error");
    return str;
}

Object *Int_add(IntClass *this, IntClass *other)
{
    int xx;

    if (this == NULL || other == NULL)
        return NULL;
    xx = this->x + other->x;
    return new(Int, xx);
}

Object *Int_sub(IntClass *this, IntClass *other)
{
    int xx;

    if (this == NULL || other == NULL)
        return NULL;
    xx = this->x - other->x;
    return new(Int, xx);
}

Object *Int_mul(IntClass *this, IntClass *other)
{
    int xx;

    if (this == NULL || other == NULL)
        return NULL;
    xx = this->x * other->x;
    return new(Int, xx);
}

Object *Int_div(IntClass *this, IntClass *other)
{
    int xx;

    if (this == NULL || other == NULL || other->x == 0)
        return NULL;
    xx = this->x / other->x;
    return new(Int, xx);
}

bool Int_eq(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    return this->x == other->x;
}


bool Int_gt(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    return this->x > other->x;
}

bool Int_lt(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    return this->x < other->x;
}
// Create additional functions here

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(_description),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .x = 0
};

const Class   *Int = (const Class *)&_description;

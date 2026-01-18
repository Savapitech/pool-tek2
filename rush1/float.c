/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdarg.h>
#include <stdio.h>

#include "float.h"
#include "object.h"
#include "new.h"

typedef struct
{
    Class   base;
    float     x;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->x = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
}

char *Float_str(FloatClass *this)
{
    char *str;

    if (!asprintf(&str, "<%s (%.6f)>", ((Class *)this)->__name__, this->x))
        raise("Asprintf error");
    return str;
}

Object *Float_add(FloatClass *this, FloatClass *other)
{
    float xx;

    if (this == NULL || other == NULL)
        return NULL;
    xx = this->x + other->x;
    return new(Float, xx);
}

Object *Float_sub(FloatClass *this, FloatClass *other)
{
    float xx;

    if (this == NULL || other == NULL)
        return NULL;
    xx = this->x - other->x;
    return new(Float, xx);
}

Object *Float_mul(FloatClass *this, FloatClass *other)
{
    float xx;

    if (this == NULL || other == NULL)
        return NULL;
    xx = this->x * other->x;
    return new(Float, xx);
}

Object *Float_div(FloatClass *this, FloatClass *other)
{
    float xx;

    if (this == NULL || other == NULL || other->x == 0)
        return NULL;
    xx = this->x / other->x;
    return new(Float, xx);
}

bool Float_eq(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    return this->x == other->x;
}


bool Float_gt(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    return this->x > other->x;
}

bool Float_lt(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL)
        return false;
    return this->x < other->x;
}

// Create additional functions here

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(_description),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .x = 0
};

const Class   *Float = (const Class *)&_description;

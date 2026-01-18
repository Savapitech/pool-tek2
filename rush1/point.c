/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdarg.h>
#include <stdio.h>

#include "point.h"
#include "object.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    (void)this;
}

char *Point_str(PointClass *this)
{
    char *str;

    if (!asprintf(&str, "<%s (%d, %d)>", ((Class *)this)->__name__, this->x, this->y))
        raise("Asprintf error");
    return str;
}

Object *Point_add(PointClass *this, PointClass *other)
{
    int xx;
    int yy;

    if (this == NULL || other == NULL)
        return NULL;
    xx = this->x + other->x;
    yy = this->y + other->y;
    return new(Point, xx, yy);
}

Object *Point_sub(PointClass *this, PointClass *other)
{
    int xx;
    int yy;

    if (this == NULL || other == NULL)
        return NULL;
    xx = this->x - other->x;
    yy = this->y - other->y;
    return new(Point, xx, yy);
}

// Create additional functions here

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(_description),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;

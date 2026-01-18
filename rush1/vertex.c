/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
}

char *Vertex_str(VertexClass *this)
{
    char *str;

    if (!asprintf(&str, "<%s (%d, %d, %d)>", ((Class *)this)->__name__, this->x, this->y, this->z))
        raise("Asprintf error");
    return str;
}

static Object *Vertex_add(VertexClass *this, VertexClass *other)
{
    if (this == NULL || other == NULL)
        return NULL;
    return new(Vertex, this->x + other->x, this->y + other->y, this->z + other->z);
}

Class *Vertex_sub(VertexClass *this, VertexClass *other)
{
    int xx;
    int yy;
    int zz;

    if (this == NULL || other == NULL)
        return NULL;

    xx = this->x - other->x;
    yy = this->y - other->y;
    zz = this->z - other->z;

    return new(Vertex, xx, yy, zz);
}

static Object *Vertex_mul(VertexClass *this, VertexClass *other)
{
    if (this == NULL || other == NULL)
        return NULL;
    return new(Vertex, this->x * other->x, this->y * other->y, this->z * other->z);
}

static Object *Vertex_div(VertexClass *this, VertexClass *other)
{
    if (this == NULL || other == NULL)
        return NULL;
    if (other->x == 0 || other->y == 0 || other->z == 0)
        return NULL;
    return new(Vertex, this->x / other->x, this->y / other->y, this->z / other->z);
}

static bool Vertex_eq(VertexClass *this, VertexClass *other)
{
    if (this == NULL || other == NULL)
        return NULL;
    return (this->x == other->x && this->y == other->y && this->z == other->z);
}


// Create additional functions here

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(_description),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Vertex_sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Vertex_mul,
        .__div__ = (binary_operator_t)&Vertex_div,
        .__eq__ = (binary_comparator_t)&Vertex_eq,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;

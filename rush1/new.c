/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** new.c
*/

#include "new.h"
#include "object.h"
#include "stdarg.h"

Object  *new(const Class *class, ...)
{
    va_list ap;
    Object *new_class; 
    
    va_start(ap, class);
    new_class = calloc(1, class->__size__);
    if (new_class == NULL)
        raise("Calloc error in new");
    memcpy(new_class, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(new_class, &ap);
    va_end(ap);
    return new_class;
}

Object *va_new(const Class *class, va_list *ap)
{
    Object * new_class = calloc(1, class->__size__);

    if (new_class == NULL)
        raise("Calloc error in new");
    memcpy(new_class, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(new_class, ap);
    return new_class;
}


void delete(Object *ptr)
{
    const struct Class **cp = ptr;

    if(ptr && *cp && ((Class *)ptr)->__dtor__)
        ((Class *)ptr)->__dtor__(ptr);;
    free(ptr);
}

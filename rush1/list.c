
/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdarg.h>
#include "object.h"
#include "list.h"
#include "new.h"

typedef struct
{
    Container   base;
    Class       *_type;
    size_t      _size;
    list_t *_list;
}   ListClass;

typedef struct {
    Iterator    base;
    ListClass  *_lclass;
    node_t     *current;
    size_t      _idx;
}   ListIteratorClass;

static void     ListIterator_ctor(ListIteratorClass *this, va_list *args)
{
    this->_lclass = va_arg(*args, ListClass *);
    this->_idx = va_arg(*args, int);
    if (!this->_idx)
        this->current = this->_lclass->_list->head;
    else
        this->current = this->_lclass->_list->tail;
}

static bool     ListIterator_eq(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx == other->_idx);
}

static bool     ListIterator_gt(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx > other->_idx);
}

static bool     ListIterator_lt(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx < other->_idx);
}

static void     ListIterator_incr(ListIteratorClass *this)
{
    if (this->current->next == NULL)
        return;
    this->_idx += 1;
    this->current = this->current->next;
}

static Object   *ListIterator_getval(ListIteratorClass *this)
{
    return this->current->data;
}

static void     ListIterator_setval(ListIteratorClass *this, ...)
{
    va_list list;

    va_start(list, this);
    free(this->current->data);
    this->current->data = va_new(this->_lclass->_type, &list);
    va_end(list);
}

static const ListIteratorClass   _iteratorDescription = {
    {   /* Iterator struct */
        {   /* Class struct */
            .__size__ = sizeof(_iteratorDescription),
            .__name__ = "ListIterator",
            .__ctor__ = (ctor_t)&ListIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ListIterator_eq,
            .__gt__ = (binary_comparator_t)&ListIterator_gt,
            .__lt__ = (binary_comparator_t)&ListIterator_lt,
        },
        .__incr__ = (incr_t)&ListIterator_incr,
        .__getval__ = (getval_t)&ListIterator_getval,
        .__setval__ = (setval_t)&ListIterator_setval,
    },
    ._lclass = NULL,
    ._idx = 0
};

static const Class    *ListIterator = (const Class *)&_iteratorDescription;


static void     List_ctor(ListClass *this, va_list *args)
{ 
    va_list new_args;

    this->_size = va_arg(*args, size_t);
    this->_type = va_arg(*args, Class *);
    this->_list = create_list();
    if (this->_list == NULL && this->_size)
        raise("Cannot malloc list");
    for (size_t i = 0; i < this->_size; i++) {
        va_copy(new_args, *args);
        lpushback(this->_list, va_new(this->_type, &new_args));
        va_end(new_args);
    }
}

static void     List_dtor(ListClass *this)
{
    node_t *next = this->_list->head->next;
    
    for (node_t *cur = this->_list->head; cur != NULL; cur = next) {
        next = cur->next;
        free(cur->data);
    }
    free(this->_list);
}

static size_t   List_len(ListClass *this)
{
    return (this->_size);
}

static Iterator *List_begin(ListClass *this)
{
    return (new(ListIterator, this, 0));
}

static Iterator *List_end(ListClass *this)
{
    return (new(ListIterator, this, this->_size - 1));
}

static Object   *List_getitem(ListClass *this, ...)
{
    va_list ap;
    size_t index;
    size_t i = 0;

    va_start(ap, this);
    index = va_arg(ap, size_t);

    for (node_t *cur = this->_list->head; cur != NULL; cur = cur->next) {
        if (i == index) {
            va_end(ap);
            return cur->data;
        }
        i++;
    }
    va_end(ap);
    return NULL;
}

static void     List_setitem(ListClass *this, ...)
{
    va_list ap;
    size_t index;
    size_t i = 0;

    va_start(ap, this);
    index = va_arg(ap, size_t);

    for (node_t *cur = this->_list->head; cur != NULL; cur = cur->next) {
        if (i == index) {
            delete(cur->data);
            cur->data = va_new(this->_type, &ap);
            va_end(ap);
            return;
        }
        i++;
    }
    va_end(ap);
}

static void List_pushfront(ListClass *this, ...)
{
    va_list ap;

    if (!this)
        return;
    va_start(ap, this);
    lpushfront(this->_list, va_new(this->_type, &ap));
    va_end(ap);
    this->_size++;
}


static void List_pushback(ListClass *this, ...)
{
    va_list ap;

    if (!this)
        return;
    va_start(ap, this);
    lpushback(this->_list, va_new(this->_type, &ap));
    va_end(ap);
    this->_size++;
}

static void List_popfront(ListClass *this)
{
    if (!this)
        return;
    lpopfront(this->_list);
    this->_size--;
}

static void List_popback(ListClass *this)
{
    if (!this)
        return;
    lpopback(this->_list);
    this->_size--;
}

static const ListClass   _description = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(_description),
            .__name__ = "List",
            .__ctor__ = (ctor_t)&List_ctor,
            .__dtor__ = (dtor_t)&List_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&List_len,
        .__begin__ = (iter_t)&List_begin,
        .__end__ = (iter_t)&List_end,
        .__getitem__ = (getitem_t)&List_getitem,
        .__setitem__ = (setitem_t)&List_setitem,
        .__pushfront__ = (pushfront_t)&List_pushfront,
        .__pushback__ = (pushback_t)&List_pushback,
        .__popfront__ = (popfront_t)&List_popfront,
        .__popback__ = (popback_t)&List_popback
    },
    ._type = NULL,
    ._size = 0,
    ._list = NULL
};

const Class   *List = (const Class *)&_description;

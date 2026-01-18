/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** Exercice 05
*/

#pragma once

#include "object.h"
#include "iterator.h"
#include "raise.h"

typedef struct Container_s Container;

typedef Iterator *(*iter_t)(Container *this);
typedef size_t (*len_t)(Container *this);
typedef Object *(*getitem_t)(Container *this, ...);
typedef void (*setitem_t)(Container *this, ...);
typedef void (*pushfront_t)(Container *this, ...);
typedef void (*pushback_t)(Container *this, ...);
typedef void (*popback_t)(Container *this);
typedef void (*popfront_t)(Container *this);

struct Container_s {
    Class       base;
    len_t       __len__;
    iter_t      __begin__;
    iter_t      __end__;
    getitem_t   __getitem__;
    setitem_t   __setitem__;
    pushfront_t   __pushfront__;
    pushback_t   __pushback__;
    popfront_t   __popfront__;
    popback_t   __popback__;
};

#define len(c)          ((Container *)c)->__len__(c)
#define begin(c)        ((Container *)c)->__begin__(c)
#define end(c)          ((Container *)c)->__end__(c)
#define getitem(c, ...) ((Container *)c)->__getitem__(c, __VA_ARGS__)
#define setitem(c, ...) ((Container *)c)->__setitem__(c, __VA_ARGS__)
#define pushfront(c, ...) ((Container *)c)->__pushfront__(c, __VA_ARGS__)
#define pushback(c, ...) ((Container *)c)->__pushback__(c, __VA_ARGS__)
#define popfront(c) ((Container *)c)->__popfront__(c)
#define popback(c) ((Container *)c)->__popback__(c)

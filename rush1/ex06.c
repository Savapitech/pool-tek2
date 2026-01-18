/*
** EPITECH PROJECT, 2026
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include <stdio.h>
#include "list.h"
#include "int.h"
#include "new.h"

int         main(void)
{
    Object  *list = new(List, 10, Int, 0);
    Object  *it = begin(list);
    Object  *it_end;
    char *str;

    pushback(list, 0);
    printf("list size: %zu\n", len(list));
    setitem(list, 5, 12);
    setitem(list, 6, 13);
    it_end = end(list);
    while (lt(it, it_end))
    {
        str = str(getval(it));
        printf("%s\n", str);
        free(str);
        incr(it);
    }
    delete(it);
    delete(it_end);
    delete(list);
    return (0);
}

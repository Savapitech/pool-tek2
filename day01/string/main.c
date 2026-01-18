/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parse_alias
*/

#include <stdio.h>

#include "./string.h"

void test2(void)
{
    string_t s;

    string_init(&s, "Foo");
    s.append(&s, "Bar\n");
    s.print(&s);
    s.clear(&s);
    s.append(&s, "Hello");
    s.append(&s, " ");
    s.append(&s, "World\n");
    s.print(&s);
    string_destroy(&s);
}

int main(void)
{
    string_t string = {0};
    const char *ss = "aaa";

    string_init(&string, ss);
    printf("Empty ?\t [%d]\n", string.empty(&string));
    printf("Length\t [%lu]\n", string.length(&string));
    printf("At\t [%c]\n", string.at(&string, 2));
    printf("Print\t [");
    string.print(&string);
    printf("]\n");
    printf("Data\t [%s]\n", string.data(&string));
    string.clear(&string);
    printf("After clear\t [%s]\n", string.data(&string));
    string.assign(&string, "bbb");
    printf("After assign\t [%s]\n", string.data(&string));
    string.append(&string, "ccc");
    printf("After append\t [%s]\n", string.data(&string));
    string_destroy(&string);
    test2();
    return (0);
}

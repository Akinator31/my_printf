/*
** EPITECH PROJECT, 2024
** my_get_next_char.c
** File description:
** my_get_next_char function for my_printf project
*/

#include "../../include/my.h"

int get_next_char(const char *format, int *index)
{
    int i = *index + 1;
    int result = 0;

    for (i; my_is_a_specifier(format[i]) == FALSE; i++) {
        result += 1;
    }
    return result + 1;
}

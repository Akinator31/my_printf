/*
** EPITECH PROJECT, 2024
** flag_plus.c
** File description:
** flag_plus finder for my_printf project
*/

#include "../../include/my.h"

int flag_plus_finder(const char *format, int *index)
{
    int i = *index + 1;

    for (i; my_is_a_specifier(format[i]) == FALSE; i++) {
        if (format[i] == '+')
            return TRUE;
    }
    return FALSE;
}

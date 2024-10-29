/*
** EPITECH PROJECT, 2024
** flags_space.c
** File description:
** flag_space_finder function for my_printf project
*/

#include "../../include/my.h"

int flag_space_finder(const char *format, int *index)
{
    int i = *index + 1;

    for (i; my_is_a_specifier(format[i]) == FALSE; i++) {
        if (my_is_a_number(format[i]) == TRUE)
            return FALSE;
        if (format[i] == ' ')
            return TRUE;
    }
    return FALSE;
}

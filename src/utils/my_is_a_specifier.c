/*
** EPITECH PROJECT, 2024
** my_is_a_flag.c
** File description:
** my_is_a_flag function for my_printf project
*/

#include "../../include/my.h"

int my_is_a_specifier(char actual_char)
{
    char specifiers_arr[] = {
        'd', 'i', 's', 'c', '%', 'p', 'o',
        'x', 'X', 'n', 'f', 'F', 'u', 'e', 'E',
        'b', 'S', 'a', '?'
    };
    int i;

    for (i = 0; specifiers_arr[i] != '?'; i++) {
        if (actual_char == specifiers_arr[i])
            return TRUE;
    }
    return FALSE;
}

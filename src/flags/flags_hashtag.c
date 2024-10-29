/*
** EPITECH PROJECT, 2024
** flags_hashtag.c
** File description:
** flag_hashtag_finder function for my_printf project
*/

#include "../../include/my.h"

int flag_hashtag_finder(const char *format, int *index)
{
    int i = *index + 1;

    for (i; my_is_a_specifier(format[i]) == FALSE; i++) {
        if ((format[i] == '#') && my_is_a_specifier(format[i + 1]) == TRUE)
            return my_get_id_of_specifier(format[i + 1]);
    }
    return FALSE;
}

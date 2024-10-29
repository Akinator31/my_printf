/*
** EPITECH PROJECT, 2024
** is_good_format.c
** File description:
** is_good_format function for my_printf project
*/

#include "../../include/my.h"

int my_is_good_format(const char *format, int index)
{
    int i = index + 1;
    int number_find = 0;

    for (i; my_is_a_specifier(format[i]) == FALSE; i++) {
        if ((my_is_a_flag(format[i]) == FALSE)
            && (my_is_a_number(format[i]) == FALSE))
            return FALSE;
        if (my_is_a_flag(format[i]) == FALSE) {
            number_find = 1;
            continue;
        }
        if ((number_find == 1) && (my_is_a_flag(format[i]) == TRUE)
            && (format[i] != '0'))
            return FALSE;
        if ((format[i] == '#') && (my_is_a_specifier(format[i + 1]) == FALSE))
            return FALSE;
    }
    return my_get_id_of_specifier(format[i]);
}

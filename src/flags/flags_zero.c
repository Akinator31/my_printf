/*
** EPITECH PROJECT, 2024
** flags_zero.c
** File description:
** flag_zero_finder function for my_printf project
*/

#include "../../include/my.h"
#include <stdarg.h>

int flag_zero_finder(const char *format, int *index)
{
    int i = *index + 1;
    int finded = 0;

    for (i; my_is_a_specifier(format[i]) == FALSE; i++) {
        if (format[i] == '0')
            finded = 1;
        if ((my_is_a_number(format[i]) == TRUE) && (finded == 1))
            return get_absolute_value_of_int(my_getnbr(format + i));
    }
    if (finded > 0)
        return 1;
    return 0;
}

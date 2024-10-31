/*
** EPITECH PROJECT, 2024
** flag_minus.c
** File description:
** flag_minus_finder for my_printf project
*/

#include "../../include/my.h"
#include <stdlib.h>
#include <stdarg.h>

int flag_minus_finder(const char *format, int *index)
{
    int i = *index + 1;
    int finded = 0;

    for (i; my_is_a_specifier(format[i]) == FALSE; i++) {
        if (format[i] == '-')
            finded = 1;
        if ((my_is_a_number(format[i]) == TRUE) && (finded == 1))
            return get_absolute_value_of_int(my_getnbr(format + i));
    }
    if (finded > 0)
        return 1;
    return 0;
}

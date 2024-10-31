/*
** EPITECH PROJECT, 2024
** print_float_min.c
** File description:
** print_float_min function for my_printf project
*/

#include "../../include/my.h"
#include <stdarg.h>

void print_float_min(va_list *list, int *nb_output_char,
    int *index, const char *format)
{
    double value = va_arg(*list, double);
    int nb_char_printed = my_put_float(value, 0);

    *nb_output_char += nb_char_printed;
    *index += 1;
}

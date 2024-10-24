/*
** EPITECH PROJECT, 2024
** print_float.c
** File description:
** print_float function for my_printf project (%f)
*/

#include "../../include/my.h"
#include <stdarg.h>

void print_float(va_list *list, int *nb_output_char)
{
    float value = va_arg(*list, double);

    *nb_output_char += my_put_float(value);
}

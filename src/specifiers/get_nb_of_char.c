/*
** EPITECH PROJECT, 2024
** get_nb_of_char.c
** File description:
** get_number_of_char function for my_printf project
*/

#include "../../include/my.h"
#include <stdarg.h>

void get_nb_of_char(va_list *list, int *nb_output_char,
    int *index, const char *format)
{
    int *result = va_arg(*list, int *);

    *result = *nb_output_char;
    *index += 1;
}

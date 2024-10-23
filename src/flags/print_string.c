/*
** EPITECH PROJECT, 2024
** print_string.c
** File description:
** print_string function for my_printf project (%s)
*/

#include "../../include/my.h"

void print_string(va_list *list, int *nb_output_char)
{
    char *str = (char *)va_arg(*list, char *);

    my_putstr(str);
}

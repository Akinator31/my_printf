/*
** EPITECH PROJECT, 2024
** print_percent.c
** File description:
** print_percent function for my_printf project (%%)
*/

#include "../../include/my.h"

void print_percent(va_list *list, int *nb_output_char,
    int *index, const char *format)
{
    my_putchar('%');
    *nb_output_char++;
    *index += 1;
}

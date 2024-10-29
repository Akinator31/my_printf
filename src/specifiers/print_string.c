/*
** EPITECH PROJECT, 2024
** print_string.c
** File description:
** print_string function for my_printf project (%s)
*/

#include "../../include/my.h"

void print_string(va_list *list, int *nb_output_char,
    int *index, const char *format)
{
    char *str = va_arg(*list, char *);
    int nb_char_printed = 0;

    if (my_strlen(str) == 0)
        my_putchar(' ');
    nb_char_printed = my_putstr(str);
    *nb_output_char += nb_char_printed;
    *index += 1;
}

/*
** EPITECH PROJECT, 2024
** print_char.c
** File description:
** print_char function for my_printf project (%c)
*/

#include "../../include/my.h"

void print_char(va_list *list, int *nb_output_char,
    int *index, const char *format)
{
    char character = va_arg(*list, int);
    int flag_minus = flag_minus_finder(format, index);

    my_putchar(character);
    *nb_output_char += 1;
    *index += get_next_char(format, index);
    if (flag_minus > 0)
        for (int i = 0; i < flag_minus - 1; i++) {
            my_putchar(' ');
            *nb_output_char += 1;
        }
}

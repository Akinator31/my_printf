/*
** EPITECH PROJECT, 2024
** print_char.c
** File description:
** print_char function for my_printf project (%c)
*/

#include "../../include/my.h"

void print_char(va_list *list, int *nb_output_char)
{
    char character = va_arg(*list, int);

    my_putchar(character);
}

/*
** EPITECH PROJECT, 2024
** print_dec_oct_hex_integer.c
** File description:
** print_dec_oct_hex_integer function for my_printf project (%d and %i)
*/

#include "../../include/my.h"

void print_dec_oct_hex_integer(va_list *list, int *nb_output_char)
{
    int value = va_arg(*list, int);

    *nb_output_char += my_put_nbr(value);
}

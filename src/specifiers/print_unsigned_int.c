/*
** EPITECH PROJECT, 2024
** print_unsigned_int.c
** File description:
** print_unsigned_int function for the my_printf project
*/

#include "../../include/my.h"
#include <stdarg.h>

void print_unsigned_int(va_list *list, int *nb_output_char,
    int *index, const char *format)
{
    unsigned int value = va_arg(*list, unsigned int);
    int nb_char_printed = my_put_unsigned_nbr(value);

    *nb_output_char += nb_char_printed;
    *index += 1;
}

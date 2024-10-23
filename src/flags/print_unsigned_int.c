/*
** EPITECH PROJECT, 2024
** print_unsigned_int.c
** File description:
** print_unsigned_int function for the my_printf project
*/

#include "../../include/my.h"
#include <stdarg.h>

void print_unsigned_int(va_list *list, int *nb_output_char)
{
    unsigned int value = va_arg(*list, unsigned int);

    *nb_output_char += my_put_unsigned_nbr(value);
}

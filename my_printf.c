/*
** EPITECH PROJECT, 2024
** mini_printf.c
** File description:
** A simple version of printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"

static const format_specifier_t specifier_arr[] = {
    {'d', &print_dec_oct_hex_integer},
    {'i', &print_dec_oct_hex_integer},
    {'s', &print_string},
    {'c', &print_char},
    {'%', &print_percent},
    {'p', &print_pointer},
    {'o', &print_octal},
    {'u', &print_unsigned_int},
    {'x', &print_hexa_min},
    {'X', &print_hexa_maj},
    {'n', &get_nb_of_char},
    {'f', &print_float_min},
    {'F', &print_float_maj},
    {'?', NULL}
};

void compute(int *nb_output_char, const char *format, int index, va_list *list)
{
    int i;

    for (i = 0; specifier_arr[i].f != NULL; i++) {
        if (format[index + 1] == specifier_arr[i].format_specifier) {
            (*specifier_arr[i].f)(list, nb_output_char);
        }
    }
}

int my_printf(const char *restrict format, ...)
{
    int i;
    va_list list;
    int nb_output_char = 0;
    int size_str = my_strlen(format);

    va_start(list, format);
    for (i = 0; i < size_str; i++) {
        if ((format[i] == '%') && (format[i + 1] != '\0')) {
            compute(&nb_output_char, format, i, &list);
            i += 1;
            continue;
        }
        my_putchar(format[i]);
        nb_output_char++;
    }
    va_end(list);
    return nb_output_char;
}

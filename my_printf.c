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
    {'d', &print_dec_oct_hex_integer, 2},
    {'i', &print_dec_oct_hex_integer, 3},
    {'s', &print_string, 4},
    {'c', &print_char, 5},
    {'%', &print_percent, 6},
    {'p', &print_pointer, 7},
    {'o', &print_octal, 8},
    {'u', &print_unsigned_int, 9},
    {'x', &print_hexa_min, 10},
    {'X', &print_hexa_maj, 11},
    {'n', &get_nb_of_char, 12},
    {'f', &print_float_min, 13},
    {'F', &print_float_maj, 14},
    {'e', &print_e_min, 15},
    {'E', &print_e_maj, 16},
    {'b', &print_binary, 17},
    {'S', &print_strupcase, 18},
    {'a', &print_a_min, 19},
    {'?', NULL, 84}
};

int my_get_id_of_specifier(char specifier)
{
    int i = 0;

    for (i; specifier_arr[i].f != NULL; i++) {
        if (specifier_arr[i].format_specifier == specifier)
            return specifier_arr[i].id;
    }
}

int compute(int *nb_output_char, const char *format, int index, va_list *list)
{
    int i;
    int specifier = my_is_good_format(format, index);

    if (specifier == FALSE) {
        my_putchar('%');
        my_putchar(format[index + 1]);
        return index + 1;
    }
    for (i = 0; specifier_arr[i].f != NULL; i++) {
        if (specifier == specifier_arr[i].id) {
            (*specifier_arr[i].f)(list, nb_output_char, &index, format);
        }
    }
    return index;
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
            i = compute(&nb_output_char, format, i, &list);
            continue;
        }
        my_putchar(format[i]);
        nb_output_char++;
    }
    va_end(list);
    return nb_output_char;
}

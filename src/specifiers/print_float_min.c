/*
** EPITECH PROJECT, 2024
** print_float_min.c
** File description:
** print_float_min function for my_printf project
*/

#include "../../include/my.h"
#include <stdarg.h>

void print_float_min(va_list *list, int *nb_output_char,
    int *index, const char *format)
{
    double value = va_arg(*list, double);
    int nb_char_printed = 0;
    int flag_plus = flag_plus_finder(format, index);
    int flag_space = flag_space_finder(format, index);
    int flag_minus = flag_minus_finder(format, index) - 1;
    int flag_zero = flag_zero_finder(format, index);
    int flag_hashtag = flag_hashtag_finder(format, index);
    int *flags_arr[] = {&flag_plus, &flag_space, &flag_hashtag,
        &flag_minus, &flag_zero};

    apply_plus_and_space_flags_for_int_specifier(flag_space,
        flag_plus, (int)value);
    apply_minus_and_zero_flags_for_float_specifier(flags_arr, value);
    nb_char_printed = my_put_float(value, 0);
    *nb_output_char += nb_char_printed;
    *index += get_next_char(format, index);
    apply_good_space_for_int_specifier(flag_minus, flag_plus,
        flag_space, nb_char_printed);
}

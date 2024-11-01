/*
** EPITECH PROJECT, 2024
** print_strupcase.c
** File description:
** print_strupcase function for my_printf project
*/

#include "../../include/my.h"
#include <stdarg.h>

void print_strupcase(va_list *list, int *nb_output_char,
    int *index, const char *format)
{
    char *result = va_arg(*list, char *);
    int nb_char_printed = 0;
    int strlength = my_strlen(result);
    int flag_plus = flag_plus_finder(format, index);
    int flag_space = flag_space_finder(format, index);
    int flag_minus = flag_minus_finder(format, index);
    int flag_zero = flag_zero_finder(format, index);
    int *flags_arr[] = {&flag_plus, &flag_space,
        &flag_minus, &flag_zero};

    apply_plus_and_space_flags_for_string_specifier(flag_space,
        flag_plus);
    apply_minus_and_zero_flags_for_string_specifier(flags_arr, result);
    nb_char_printed = my_strupcase(result);
    *nb_output_char += nb_char_printed;
    *index += get_next_char(format, index);
    apply_good_space_for_string_specifier(flag_minus, flag_plus,
        flag_space, nb_char_printed);
}

/*
** EPITECH PROJECT, 2024
** print_dec_oct_hex_integer.c
** File description:
** print_dec_oct_hex_integer function for my_printf project (%d and %i)
*/

#include "../../include/my.h"

void print_dec_oct_hex_integer(va_list *list, int *nb_output_char,
    int *index, const char *format)
{
    int value = va_arg(*list, int);
    int nb_char_printed = 0;
    int flag_plus = flag_plus_finder(format, index);
    int flag_space = flag_space_finder(format, index);
    int flag_hashtag = flag_hashtag_finder(format, index);
    int flag_minus = flag_minus_finder(format, index);
    int flag_zero = flag_zero_finder(format, index);
    int *flags_arr[] = {&flag_plus, &flag_space, &flag_hashtag,
        &flag_minus, &flag_zero};

    apply_plus_and_space_flags_for_int_specifier(flag_space,
        flag_plus, value);
    apply_minus_and_zero_flags_for_int_specifier(flags_arr, value);
    nb_char_printed = my_put_nbr(value);
    *nb_output_char += nb_char_printed;
    *index += get_next_char(format, index);
    apply_good_space_for_int_specifier(flag_minus, flag_plus,
        flag_space, nb_char_printed);
}

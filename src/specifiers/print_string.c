/*
** EPITECH PROJECT, 2024
** print_string.c
** File description:
** print_string function for my_printf project (%s)
*/

#include "../../include/my.h"

void print_string(va_list *list, int *nb_output_char,
    int *index, const char *format)
{
    char *str = va_arg(*list, char *);
    int nb_char_printed = 0;
    int flag_minus = flag_minus_finder(format, index);
    int flag_zero = flag_zero_finder(format, index);

    if ((flag_zero > 0) && (flag_minus == FALSE)) {
        for (int i = 0; i < (flag_zero - my_strlen(str)); i++) {
            my_putchar(' ');
            *nb_output_char += 1;
        }
    }
    nb_char_printed = my_putstr(str);
    *nb_output_char += nb_char_printed;
    *index += get_next_char(format, index);
    if (flag_minus > 0) {
        for (int i = 0; i < (flag_minus - nb_char_printed); i++) {
            my_putchar(' ');
            *nb_output_char += 1;
        }
    }
}

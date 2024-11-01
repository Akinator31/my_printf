/*
** EPITECH PROJECT, 2024
** flags_apply_string.c
** File description:
** flags_apply for %S specifier
*/

#include "../../include/my.h"

void apply_plus_and_space_flags_for_string_specifier(int
    flag_space, int flag_plus)
{
    if ((flag_space == TRUE) && (flag_plus == TRUE))
        my_putchar('+');
    if ((flag_space == TRUE) && (flag_plus == FALSE))
        my_putchar(' ');
    if ((flag_space == FALSE) && (flag_plus == TRUE))
        my_putchar('+');
}

void apply_minus_and_zero_flags_for_string_specifier(int
    **flags_arr, char *result)
{
    if ((*flags_arr[3] > 0) && (*flags_arr[2] == 0)
        && ((*flags_arr[0] == 1) || (*flags_arr[1] == 1)))
        for (int e = 0; e < (*flags_arr[3] - my_strlen(result) - 1); e++)
            my_putchar('0');
    if ((*flags_arr[3] > 0) && (*flags_arr[2] == 0)
        && ((*flags_arr[0] == 0) && (*flags_arr[1] == 0)))
        for (int j = 0; j < (*flags_arr[3] - my_strlen(result)); j++)
            my_putchar('0');
}

void apply_good_space_for_string_specifier(int
    flag_minus, int flag_plus, int flag_space, int nb_char_printed)
{
    if ((flag_minus > 0) && ((flag_plus == 1) || (flag_space == 1)))
        for (int i = 0; i < (flag_minus - nb_char_printed - 1); i++)
            my_putchar(' ');
    if ((flag_minus > 0) && ((flag_plus == 0) && (flag_space == 0)))
        for (int o = 0; o < (flag_minus - nb_char_printed); o++)
            my_putchar(' ');
}

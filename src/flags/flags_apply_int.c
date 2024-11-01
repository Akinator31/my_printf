/*
** EPITECH PROJECT, 2024
** flags_apply.c
** File description:
** flags_apply function for all flags in my_printf project
*/

#include "../../include/my.h"

void apply_plus_and_space_flags_for_int_specifier(int
    flag_space, int flag_plus, int value)
{
    if ((flag_space == TRUE) && (flag_plus == TRUE) && (value >= 0))
        my_putchar('+');
    if ((flag_space == TRUE) && (flag_plus == FALSE))
        my_putchar(' ');
    if ((flag_space == FALSE) && (flag_plus == TRUE) && (value >= 0))
        my_putchar('+');
}

void apply_good_space_for_int_specifier(int
    flag_minus, int flag_plus, int flag_space, int nb_char_printed)
{
    if ((flag_minus > 0) && ((flag_plus == 1) || (flag_space == 1)))
        for (int i = 0; i < (flag_minus - nb_char_printed - 1); i++)
            my_putchar(' ');
    if ((flag_minus > 0) && ((flag_plus == 0) && (flag_space == 0)))
        for (int o = 0; o < (flag_minus - nb_char_printed); o++)
            my_putchar(' ');
}

void apply_minus_and_zero_flags_for_int_specifier(int
    **flags_arr, int value)
{
    if ((*flags_arr[4] > 0) && (*flags_arr[3] == 0)
        && ((*flags_arr[0] == 1) || (*flags_arr[1] == 1)))
        for (int e = 0; e < (*flags_arr[4] - my_get_nb_length(value) - 1); e++)
            my_putchar('0');
    if ((*flags_arr[4] > 0) && (*flags_arr[3] == 0)
        && ((*flags_arr[0] == 0) && (*flags_arr[1] == 0)))
        for (int j = 0; j < (*flags_arr[4] - my_get_nb_length(value)); j++)
            my_putchar('0');
}

void apply_minus_and_zero_flags_for_float_specifier(int
    **flags_arr, float value)
{
    if ((*flags_arr[4] > 0) && (*flags_arr[3] == 0)
        && ((*flags_arr[0] == 1) || (*flags_arr[1] == 1)))
        for (int e = 0;
            e < (*flags_arr[4] - my_float_length(value, 0) - 1); e++)
            my_putchar('0');
    if ((*flags_arr[4] > 0) && (*flags_arr[3] == 0)
        && ((*flags_arr[0] == 0) && (*flags_arr[1] == 0)))
        for (int j = 0; j < (*flags_arr[4] - my_float_length(value, 0)); j++)
            my_putchar('0');
}

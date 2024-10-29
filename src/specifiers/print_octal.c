/*
** EPITECH PROJECT, 2024
** print_octal.c
** File description:
** print_octal function for my_printf project (%o)
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

long calc_pow_8(long ptr)
{
    long power = 1;

    while (power < ptr) {
        power *= 8;
    }
    power /= 8;
    return power;
}

int len(long power_8, long pointer)
{
    int i_char = 0;
    long digit = 0;

    while (power_8 > 0) {
        digit = get_digit(pointer, power_8);
        pointer -= power_8 * digit;
        power_8 /= 8;
        i_char++;
    }
    return i_char;
}

void apply_zero_plus_hashtag_flag(const char *format, int *index,
    int *nb_output_char, int len)
{
    int flag_minus = flag_minus_finder(format, index);
    int flag_zero = flag_zero_finder(format, index);

    if ((flag_zero > 0) && (flag_minus == FALSE)) {
        for (int i = 0; i < (flag_zero - len); i++) {
            my_putchar('0');
            *nb_output_char += 1;
        }
    }
}

void apply_minus_flag(const char *format, int *index,
    int *nb_output_char, int len)
{
    int flag_minus = flag_minus_finder(format, index);

    if (flag_minus > 0) {
        for (int i = 0; i < (flag_minus - len); i++) {
            my_putchar(' ');
            *nb_output_char += 1;
        }
    }
}

void print_octal(va_list *list, int *nb_output_char,
    int *index, const char *format)
{
    long pointer = va_arg(*list, long);
    long power_8 = calc_pow_8(pointer);
    long digit = 0;
    char base[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
    int length = len(power_8, pointer);
    int flag_hashtag = flag_hashtag_finder(format, index);

    apply_zero_plus_hashtag_flag(format, index,
        nb_output_char, length);
    if (flag_hashtag > 0)
        my_putchar('0');
    while (power_8 > 0) {
        digit = get_digit(pointer, power_8);
        write(1, &base[digit], 1);
        pointer -= power_8 * digit;
        power_8 /= 8;
        *nb_output_char++;
    }
    apply_minus_flag(format, index, nb_output_char, length);
    *index += get_next_char(format, index);
}

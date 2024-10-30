/*
** EPITECH PROJECT, 2024
** print_hexa_min.c
** File description:
** print_hexa_min function for my_printf project (%o)
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

long calc_pow_hexa_maj(long ptr)
{
    long power = 1;

    while (power < ptr) {
        power *= 16;
    }
    power /= 16;
    return power;
}

int count_char_in_hexa_maj(long power, long pointer)
{
    int i_char = 0;
    long digit = 0;

    while (power > 0) {
        digit = get_digit(pointer, power);
        pointer -= power * digit;
        power /= 16;
        i_char++;
    }
    return i_char;
}

void print_hexa_maj(va_list *list, int *nb_output_char,
    int *index, const char *format)
{
    long pointer = va_arg(*list, long);
    long power_16 = calc_pow_hexa_maj(pointer);
    long digit = 0;
    int length = count_char_in_hexa_maj(power_16, pointer);
    char base[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F'};
    int flag_hashtag = flag_hashtag_finder(format, index);

    apply_zero_plus_hashtag_flag(format, index,
        nb_output_char, length);
    while (power_16 > 0) {
        digit = get_digit(pointer, power_16);
        write(1, &base[digit], 1);
        pointer -= power_16 * digit;
        power_16 /= 16;
        *nb_output_char++;
    }
    apply_minus_flag(format, index, nb_output_char, length);
    *index += get_next_char(format, index);
}

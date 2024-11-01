/*
** EPITECH PROJECT, 2024
** print_binary.c
** File description:
** print_binary function for my_printf project
*/

#include "../../include/my.h"
#include <unistd.h>

long calc_pow_hexa_binary(int ptr)
{
    long power = 1;

    while (power < ptr) {
        power *= 2;
    }
    power /= 2;
    return power;
}

int count_char_in_binary(int power, long pointer)
{
    int i_char = 0;
    long digit = 0;

    while (power > 0) {
        digit = get_digit(pointer, power);
        pointer -= power * digit;
        power /= 2;
        i_char++;
    }
    return i_char;
}

int check_neg_value(long nb)
{
    if (nb < 0)
        my_putchar('-');
    return (nb < 0) ? get_absolute_value_of_int(nb) : nb;
}

void print_binary(va_list *list, int *nb_output_char,
    int *index, const char *format)
{
    int pointer = check_neg_value(va_arg(*list, int));
    long power_2 = calc_pow_hexa_binary(pointer);
    long digit = 0;
    int length = count_char_in_binary(power_2, pointer);
    char base[] = {'0', '1'};
    int flag_hashtag = flag_hashtag_finder(format, index);

    apply_zero_plus_hashtag_flag(format, index,
        nb_output_char, length);
    while (power_2 > 0) {
        digit = get_digit(pointer, power_2);
        write(1, &base[digit], 1);
        pointer -= power_2 * digit;
        power_2 /= 2;
        *nb_output_char++;
    }
    apply_minus_flag(format, index, nb_output_char, length);
    *index += get_next_char(format, index);
}

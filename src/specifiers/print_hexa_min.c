/*
** EPITECH PROJECT, 2024
** print_hexa_min.c
** File description:
** print_hexa_min function for my_printf project (%o)
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

long calc_pow_hexa_min(long ptr)
{
    long power = 1;

    while (power < ptr) {
        power *= 16;
    }
    power /= 16;
    return power;
}

void print_hexa_min(va_list *list, int *nb_output_char,
    int *index, const char *format)
{
    long pointer = va_arg(*list, long);
    long power_16 = calc_pow_hexa_min(pointer);
    long digit = 0;
    char base[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'a', 'b', 'c', 'd', 'e', 'f'};

    while (power_16 > 0) {
        digit = get_digit(pointer, power_16);
        write(1, &base[digit], 1);
        pointer -= power_16 * digit;
        power_16 /= 16;
        *nb_output_char++;
    }
    *index += 1;
}

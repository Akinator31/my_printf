/*
** EPITECH PROJECT, 2024
** print_pointer.c
** File description:
** print_pointer function for my_printf project (%p)
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

long long calc_pow_16(unsigned long ptr)
{
    long long power = 1;

    while (power < ptr) {
        power *= 16;
    }
    power /= 16;
    return power;
}

void print_pointer(va_list *list, int *nb_output_char)
{
    unsigned long pointer = (unsigned long)va_arg(*list, void *);
    long long power_16 = calc_pow_16(pointer);
    long long digit = 0;
    char base[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
        '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    my_putstr("0x");
    while (power_16 > 0) {
        digit = get_digit(pointer, power_16);
        write(1, &base[digit], 1);
        pointer -= power_16 * digit;
        power_16 /= 16;
        *nb_output_char++;
    }
}

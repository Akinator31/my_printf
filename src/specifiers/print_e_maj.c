/*
** EPITECH PROJECT, 2024
** print_e_min.c
** File description:
** print_e_maj function for %E in my_printf project
*/

#include "../../include/my.h"
#include <stdio.h>

void print_e_maj(va_list *list, int *nb_output_char,
    int *index, const char *format)
{
    double nb = va_arg(*list, double);
    long power = count_power(nb);
    int positive;

    *index += get_next_char(format, index);
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb > 1) {
        positive = 1;
        ten_power_write(power, nb / power, positive, 1);
        return;
    }
    if (nb < 1) {
        positive = 0;
        power *= 10;
        ten_power_write(power, nb * power, positive, 1);
        return;
    }
}

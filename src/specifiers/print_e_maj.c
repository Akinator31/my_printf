/*
** EPITECH PROJECT, 2024
** print_e_min.c
** File description:
** print_e_min function for %e in my_printf project
*/

#include "../../include/my.h"
#include <stdio.h>

void after_test_zero_maj(double nb, int positive, long power)
{
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

void test_zero_true_maj(int precision)
{
    my_put_nbr(0);
    my_putchar('.');
    while (precision != 0) {
        my_put_nbr(0);
        precision--;
    }
    my_putstr("E+00");
}

void print_e_maj(va_list *list, int *nb_output_char,
    int *index, const char *format)
{
    double nb = va_arg(*list, double);
    long power = count_power(nb);
    int positive;
    int precision = 6;

    *index += get_next_char(format, index);
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb == 0) {
        test_zero_true_maj(precision);
        return;
    }
    after_test_zero_maj(nb, positive, power);
}

/*
** EPITECH PROJECT, 2024
** print_e_min.c
** File description:
** print_e_min function for %e in my_printf project
*/

#include "../../include/my.h"
#include <stdio.h>

void after_test_zero(double nb, int positive, long power, int *nb_output_char)
{
    if (nb > 1) {
        positive = 1;
        *nb_output_char += my_float_length(nb / power, 0);
        my_put_float(nb / power, 0);
        ten_power_write(power, positive, 0, nb_output_char);
        return;
    }
    if (nb < 1) {
        positive = 0;
        power *= 10;
        *nb_output_char += my_float_length(nb * power, 0);
        my_put_float(nb * power, 0);
        ten_power_write(power, positive, 0, nb_output_char);
        return;
    }
}

void test_zero_true(int precision, int *nb_output_char)
{
    my_put_nbr(0);
    my_putchar('.');
    *nb_output_char++;
    while (precision != 0) {
        my_put_nbr(0);
        precision--;
        *nb_output_char++;
    }
    my_putstr("e+00");
    *nb_output_char += 4;
}

void print_e_min(va_list *list, int *nb_output_char,
    int *index, const char *format)
{
    double nb = va_arg(*list, double);
    long power = count_power(nb);
    int positive;
    int precision = 6;

    *index += get_next_char(format, index);
    if (nb < 0) {
        my_putchar('-');
        *nb_output_char++;
        nb *= -1;
    }
    if (nb == 0) {
        test_zero_true(precision, nb_output_char);
        return;
    }
    after_test_zero(nb, positive, power, nb_output_char);
}

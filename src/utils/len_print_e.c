/*
** EPITECH PROJECT, 2024
** len_print_e.c
** File description:
** print_e_min function for %e in my_printf project
*/

#include "../../include/my.h"
#include <stdio.h>

void after_test_zero_len(double nb, int positive, long power, int *nb_output_char)
{
    if (nb > 1) {
        positive = 1;
        *nb_output_char += my_float_length(nb / power, 0);
        ten_power_len(power, positive, 0, nb_output_char);
        return;
    }
    if (nb < 1) {
        positive = 0;
        power *= 10;
        *nb_output_char += my_float_length(nb * power, 0);
        ten_power_len(power, positive, 0, nb_output_char);
        return;
    }
}

void test_zero_true_len(int precision, int *nb_output_char)
{
    *nb_output_char++;
    while (precision != 0) {
        precision--;
        *nb_output_char++;
    }
    *nb_output_char += 4;
}

int len_print_e(double nb)
{
    long power = count_power(nb);
    int positive;
    int precision = 6;
    int nb_output_char = 0;

    if (nb < 0) {
        nb_output_char++;
        nb *= -1;
    }
    if (nb == 0) {
        test_zero_true_len(precision, &nb_output_char);
        return nb_output_char;
    }
    after_test_zero_len(nb, positive, power, &nb_output_char);
    return nb_output_char;
}

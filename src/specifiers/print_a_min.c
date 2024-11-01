/*
** EPITECH PROJECT, 2024
** print_a_min.c
** File description:
** print_a_min function for my_printf project
*/

#include "../../include/my.h"
#include <stdio.h>

int count_power_two(double nb)
{
    int exp = 0;
    double power = 1;

    if (nb > 1) {
        while (power < nb) {
            power *= 2;
            exp++;
        }
        exp--;
    }
    if (nb < 1) {
        while (power > nb) {
            power /= 2;
            exp++;
        }
        exp *= -1;
    }
    return exp;
}

double power_two(double nb)
{
    int exp = count_power_two(nb);
    double result = 2;

    if (exp > 0) {
        while (exp != 0) {
            result *= 2;
            exp--;
        }
        return result / 2;
    }
    if (exp < 0) {
        while (exp != 0) {
            result /= 2;
            exp++;
        }
        return result / 2;
    }
}

static void write_power_two(double nb, int test_power_two, int exp)
{
    exp += count_power_two(nb);
    if (test_power_two == 1)
        exp++;
    if (exp > 0)
        my_printf("p+%d", exp);
    if (exp < 0)
        my_printf("p%d", exp);
}

static double write_float_hexa(long precision,
    double calc_nb, int left_part_nb)
{
    calc_nb = (calc_nb - left_part_nb) * 16;
    left_part_nb = calc_nb;
    while (precision > -1 && calc_nb != 0) {
        if (left_part_nb <= 9)
            my_put_nbr(left_part_nb);
        else
            my_printf("%x", left_part_nb);
        calc_nb = (calc_nb - left_part_nb) * 16;
        left_part_nb = calc_nb;
        precision--;
    }
    return calc_nb;
}

double value_calc_nb(double nb, double power_of_two)
{
    double calc_nb;

    if (power_of_two > 1)
        calc_nb = nb / power_of_two;
    if (power_of_two < 1)
        calc_nb = nb * power_of_two;
    return calc_nb;
}

static int test_is_power_of_two(double power_of_two, double nb)
{
    if (nb == 2)
        power_of_two /= 2;
    if (nb == power_of_two * 2 || nb == power_of_two) {
        my_putchar('1');
        if (nb < 1) {
            write_power_two(nb, 1, -1);
            return 0;
        }
        write_power_two(nb, 1, 0);
        return 0;
    }
    return 1;
}

static void print_a_min_after_test_isneg(double nb)
{
    double power_of_two = power_two(nb);
    double calc_nb = nb / power_of_two;
    int left_part_nb = calc_nb;
    long precision = 12;

    my_putstr("0x");
    if (test_is_power_of_two(power_of_two, nb) == 0)
        return;
    my_put_nbr(left_part_nb);
    my_putchar('.');
    calc_nb = write_float_hexa(precision, calc_nb, left_part_nb);
    if (calc_nb != 0) {
        left_part_nb = calc_nb;
        my_printf("%x", left_part_nb);
    }
    write_power_two(nb, 0, 0);
}

static int case_equal_one(double nb)
{
    if (nb == 1) {
        my_putstr("0x1p+0");
        return 1;
    }
    return 0;
}

void print_a_min(va_list *list, int *nb_output_char,
    int *index, const char *format)
{
    double nb = va_arg(*list, double);

    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    if (case_equal_one(nb) == 1) {
        *index += get_next_char(format, index);
        return;
    }
    if (nb == 0) {
        my_printf("0x0p+0");
        *index += get_next_char(format, index);
        return;
    }
    print_a_min_after_test_isneg(nb);
    *index += get_next_char(format, index);
}

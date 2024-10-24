/*
** EPITECH PROJECT, 2024
** my_put_float.c
** File description:
** my_put_float for mylib
*/

#include "../../include/my.h"

void negative_number(float *nb)
{
    *nb *= -1;
    my_putchar('-');
}

int check_infinity_nan(float nb)
{
    if (nb == IS_INFINITY) {
        my_putstr("inf");
        return 1;
    }
    if (nb == IS_NAN) {
        my_putstr("nan");
        return 1;
    }
    return 0;
}

void print_floating_part(int floating_part, double temp)
{
    for (int i = 0; i < 7; i++) {
        temp *= 10;
    }
    floating_part = (int)temp;
    if ((floating_part % 10) >= 5) {
        floating_part /= 10;
        floating_part += 1;
    } else
        floating_part /= 10;
    my_put_nbr(floating_part);
}

int my_put_float(float nb)
{
    int whole_part;
    int floating_part;
    double temp;

    if (check_infinity_nan(nb) == 1)
        return 0;
    if (nb < 0)
        negative_number(&nb);
    whole_part = (int)nb;
    temp = (double)nb - whole_part;
    if (temp == 0) {
        my_put_nbr(whole_part);
        my_putstr(".000000");
        return 0;
    }
    my_put_nbr(whole_part);
    my_putchar('.');
    print_floating_part(floating_part, temp);
}

/*
** EPITECH PROJECT, 2024
** my_put_float.c
** File description:
** my_put_float for mylib
*/

#include "../../include/my.h"
#include <stdio.h>

static void negative_number(double *nb, int *nb_output_char)
{
    *nb *= -1;
    my_putchar('-');
    *nb_output_char++;
}

static int check_infinity_nan(double nb, int is_maj)
{
    if (nb == IS_INFINITY) {
        if (is_maj == 1) {
            my_putstr("INF");
            return 1;
        } else {
            my_putstr("inf");
            return 1;
        }
    }
    if (nb == IS_NAN) {
        if (is_maj == 1) {
            my_putstr("NAN");
            return 1;
        } else {
            my_putstr("nan");
            return 1;
        }
    }
    return 0;
}

void if_zero_after_coma(double nb, int *nb_c)
{
    double power_of_ten = 1;
    int exp = 0;
    int left_part = nb;
    int precision = 5;

    while (power_of_ten / 10 > nb - left_part) {
        power_of_ten /= 10;
        exp++;
    }
    while (precision != 0 && exp != 0) {
        my_putchar('0');
        *nb_c++;
        exp--;
        precision--;
    }
}

void print_float_particular_case(double nb, double temp, int *nb_c)
{
    *nb_c += my_put_nbr((int)nb) + 1;
    my_putchar('.');
    if_zero_after_coma(nb, nb_c);
    *nb_c += my_put_nbr((int)temp % 1000000);
}

void print_floating_part(int floating_part, double temp,
    int *nb_output_char, double nb)
{
    my_putchar('.');
    if_zero_after_coma(nb, nb_output_char);
    for (int i = 0; i < 7; i++) {
        temp *= 10;
    }
    floating_part = (int)temp;
    if ((floating_part % 10) >= 5) {
        floating_part /= 10;
        floating_part += 1;
    } else
        floating_part /= 10;
    *nb_output_char += my_put_nbr(floating_part);
}

static int check_special_case(double nb, int is_maj, double temp, int *nb_c)
{
    if (check_infinity_nan(nb, is_maj) == 1)
        return 1;
    temp = nb * 1000000;
    if (((int)temp % 10) == 0) {
        print_float_particular_case(nb, temp, nb_c);
        return 1;
    }
}

int my_put_float(double nb, int is_maj)
{
    int whole_part;
    int floating_part;
    double temp;
    int nb_c = 0;

    if (nb < 0)
        negative_number(&nb, &nb_c);
    if (check_special_case(nb, is_maj, temp, &nb_c) == 1)
        return nb_c;
    whole_part = (int)nb;
    temp = (double)nb - whole_part;
    if (temp == 0) {
        nb_c += my_put_nbr(whole_part) + 7;
        my_putstr(".000000");
        return nb_c;
    }
    nb_c += my_put_nbr(whole_part);
    print_floating_part(floating_part, temp, &nb_c, nb);
    return nb_c;
}

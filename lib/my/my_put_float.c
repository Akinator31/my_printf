/*
** EPITECH PROJECT, 2024
** my_put_float.c
** File description:
** my_put_float for mylib
*/

#include "../../include/my.h"

void negative_number(float *nb, int *nb_output_char)
{
    *nb *= -1;
    my_putchar('-');
    *nb_output_char++;
}

int check_infinity_nan(float nb, int is_maj)
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

void print_float_particular_case(float nb, float temp)
{
    my_put_nbr((int)nb);
    my_putchar('.');
    my_put_nbr((int)temp % 1000000);
}

void print_floating_part(int floating_part, double temp, int *nb_output_char)
{
    my_putchar('.');
    for (int i = 0; i < 7; i++) {
        temp *= 10;
    }
    floating_part = (int)temp;
    if ((floating_part % 10) >= 5) {
        floating_part /= 10;
        floating_part += 1;
    } else {
        floating_part /= 10;
        floating_part += 1;
    }
    *nb_output_char += my_put_nbr(floating_part);
}

static int check_special_case(float nb, int is_maj, float temp)
{
    if (check_infinity_nan(nb, is_maj) == 1)
        return 1;
    temp = nb * 1000000;
    if (((int)temp % 10) == 0) {
        print_float_particular_case(nb, temp);
        return 1;
    }
}

int my_put_float(float nb, int is_maj)
{
    int whole_part;
    int floating_part;
    double temp;
    int nb_output_char = 0;

    if (check_special_case(nb, is_maj, temp) == 1)
        return 0;
    if (nb < 0)
        negative_number(&nb, &nb_output_char);
    whole_part = (int)nb;
    temp = (double)nb - whole_part;
    if (temp == 0) {
        nb_output_char += my_put_nbr(whole_part) + 7;
        my_putstr(".000000");
        return nb_output_char;
    }
    nb_output_char += my_put_nbr(whole_part);
    print_floating_part(floating_part, temp, &nb_output_char);
    return nb_output_char;
}

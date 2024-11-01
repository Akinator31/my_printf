/*
** EPITECH PROJECT, 2024
** my_put_float.c
** File description:
** my_put_float for mylib
*/

#include "../../include/my.h"
#include <stdio.h>

static void negative_number_length(double *nb, int *nb_output_char)
{
    *nb *= -1;
    *nb_output_char++;
}

static int check_infinity_nan_length(double nb, int is_maj)
{
    if (nb == IS_INFINITY) {
        if (is_maj == 1) {
            return 1;
        } else {
            return 1;
        }
    }
    if (nb == IS_NAN) {
        if (is_maj == 1) {
            return 1;
        } else {
            return 1;
        }
    }
    return 0;
}

void if_zero_after_coma_length(double nb, int *nb_c)
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
        *nb_c++;
        exp--;
        precision--;
    }
}

void print_float_particular_case_length(double nb, double temp, int *nb_c)
{
    *nb_c += my_get_nb_length((int)nb) + 1;
    if_zero_after_coma_length(nb, nb_c);
    *nb_c += my_get_nb_length((int)temp % 1000000);
}

void print_floating_part_length(int floating_part, double temp,
    int *nb_output_char, double nb)
{
    if_zero_after_coma_length(nb, nb_output_char);
    for (int i = 0; i < 7; i++) {
        temp *= 10;
    }
    floating_part = (int)temp;
    if ((floating_part % 10) >= 5) {
        floating_part /= 10;
        floating_part += 1;
    } else
        floating_part /= 10;
    *nb_output_char += my_get_nb_length(floating_part);
}

static int check_special_case_length(double nb, int is_maj,
    double temp, int *nb_c)
{
    if (check_infinity_nan_length(nb, is_maj) == 1)
        return 1;
    temp = nb * 1000000;
    if (((int)temp % 10) == 0) {
        print_float_particular_case_length(nb, temp, nb_c);
        return 1;
    }
}

int my_float_length(double nb, int is_maj)
{
    int whole_part;
    int floating_part;
    double temp;
    int nb_c = 0;

    if (check_special_case_length(nb, is_maj, temp, &nb_c) == 1)
        return nb_c;
    if (nb < 0)
        negative_number_length(&nb, &nb_c);
    whole_part = (int)nb;
    temp = (double)nb - whole_part;
    if (temp == 0) {
        nb_c += my_get_nb_length(whole_part) + 7;
        return nb_c;
    }
    nb_c += my_get_nb_length(whole_part);
    print_floating_part_length(floating_part, temp, &nb_c, nb);
    return nb_c;
}

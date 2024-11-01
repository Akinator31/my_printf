/*
** EPITECH PROJECT, 2024
** write_e_power.c
** File description:
** write_e_power function for my_printf project
*/

#include "../../include/my.h"

static void write_in_min(int *nb_output_char, int positive)
{
    *nb_output_char += 2;
    if (positive == 1)
        my_putstr("E+");
    if (positive == 0)
        my_putstr("E-");
}

void write_in_maj(int *nb_output_char, int positive)
{
    *nb_output_char += 2;
    if (positive == 1)
        my_putstr("e+");
    if (positive == 0)
        my_putstr("e-");
}

double test_for_pos(double nb, long power, int positive)
{
    double nb_return;

    if (positive == 1)
        nb_return = nb / power;
    if (positive == 0)
        nb_return = nb * power;
    return nb_return;
}

void ten_power_len(long power, int positive,
    int maj, int *nb_output_char)
{
    int exp = count_power_ten(power);

    if (maj == 1)
        *nb_output_char += 2;
    if (maj == 0)
        *nb_output_char += 2;
    if (exp < 10) {
        *nb_output_char += 2;
    }
    *nb_output_char += my_get_nb_length(exp);
}

void ten_power_write(long power, int positive,
    int maj, int *nb_output_char)
{
    int exp = count_power_ten(power);

    if (maj == 1)
        write_in_min(nb_output_char, positive);
    if (maj == 0)
        write_in_maj(nb_output_char, positive);
    if (exp < 10) {
        my_put_nbr(0);
        *nb_output_char += 2;
    }
    my_put_nbr(exp);
    *nb_output_char += my_get_nb_length(exp);
}

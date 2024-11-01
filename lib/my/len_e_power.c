/*
** EPITECH PROJECT, 2024
** len_e_power.c
** File description:
** write_e_power function for my_printf project
*/

#include "../../include/my.h"

double len_test_for_pos(double nb, long power, int positive)
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
        *nb_output_char += 2;;
    if (maj == 0)
        *nb_output_char += 2;
    if (exp < 10) {
        *nb_output_char += 2;
    }
    *nb_output_char += my_get_nb_length(exp);
}

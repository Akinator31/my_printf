/*
** EPITECH PROJECT, 2024
** write_e_power.c
** File description:
** write_e_power function for my_printf project
*/

#include "../../include/my.h"

void ten_power_write(long power, double nb, int positive, int maj)
{
    int exp = count_power_ten(power);

    my_put_float(nb, 0);
    if (maj == 1) {
        if (positive == 1)
            my_putstr("E+");
        if (positive == 0)
            my_putstr("E-");
    }
    if (maj == 0) {
        if (positive == 1)
            my_putstr("e+");
        if (positive == 0)
            my_putstr("e-");
    }
    if (exp < 10)
        my_put_nbr(0);
    my_put_nbr(exp);
}

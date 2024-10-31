/*
** EPITECH PROJECT, 2024
** my_get_nb_length.c
** File description:
** my_get_nb_length function for my lib
*/

#include "../../include/my.h"

void check_neg_number(int *nb)
{
    *nb *= -1;
}

int my_get_nb_length(int nb)
{
    int divider = 1;
    int counter_digits = 1;
    int return_nb_digit;

    if (nb < 0)
        check_neg_number(&nb);
    if (nb <= 9)
        return 1;
    while (divider <= (nb / 10)) {
        counter_digits++;
        return_nb_digit = counter_digits;
        divider *= 10;
    }
    while (counter_digits > 0) {
        nb %= divider;
        counter_digits--;
        divider /= 10;
    }
    return return_nb_digit;
}

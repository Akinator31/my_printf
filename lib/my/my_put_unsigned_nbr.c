/*
** EPITECH PROJECT, 2024
** my_put_unsigned_nbr.c
** File description:
** function that print unsigned int
*/

#include "../../include/my.h"

int my_put_unsigned_nbr(unsigned int nb)
{
    unsigned int divider = 1;
    unsigned int counter_digits = 1;
    int return_nb_digit;

    while (divider <= (nb / 10)) {
        counter_digits++;
        return_nb_digit = counter_digits;
        divider *= 10;
    }
    while (counter_digits > 0) {
        my_putchar(nb / divider + 48);
        nb %= divider;
        counter_digits--;
        divider /= 10;
    }
    return return_nb_digit;
}

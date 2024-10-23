/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** task07
*/

#include "../../include/my.h"

int the_small_int(int nb)
{
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        my_putchar('1');
        my_putchar('4');
        my_putchar('7');
        my_putchar('4');
        my_putchar('8');
        my_putchar('3');
        my_putchar('6');
        my_putchar('4');
        my_putchar('8');
        return 1;
    }
    return 0;
}

void check_negative_number(int *nb)
{
    *nb *= -1;
    my_putchar('-');
}

int my_put_nbr(int nb)
{
    int divider = 1;
    int counter_digits = 1;
    int return_nb_digit;

    if (the_small_int(nb) == 0) {
        if (nb < 0)
            check_negative_number(&nb);
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
    }
    return return_nb_digit;
}

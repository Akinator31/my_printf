/*
** EPITECH PROJECT, 2024
** count_power_ten.c
** File description:
** count_power_ten function for my_printf project
*/

#include "../../include/my.h"

int count_power_ten(long power)
{
    int exp = 1;

    while (power > 10) {
        power /= 10;
        exp++;
    }
    return exp;
}

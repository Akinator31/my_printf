/*
** EPITECH PROJECT, 2024
** my_get_absolute_value_of_int.c
** File description:
** absolute value function
*/

#include "../../include/my.h"

int get_absolute_value_of_int(int nb)
{
    if (nb < 0)
        return nb * -1;
    return nb;
}

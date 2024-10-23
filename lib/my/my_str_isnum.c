/*
** EPITECH PROJECT, 2024
** my_str_isnem.c
** File description:
** task13
*/

#include "../../include/my.h"

int my_str_isnum(char const *str)
{
    int i;

    if (my_strlen(str) == 0)
        return 1;
    for (i = 0; str[i] > '\0'; i++) {
        if ((str[i] < '0') || (str[i] > '9'))
            return 0;
    }
    return 1;
}

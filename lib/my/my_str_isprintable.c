/*
** EPITECH PROJECT, 2024
** my_str_isprintable.c
** File description:
** task16
*/

#include "../../include/my.h"

int my_str_isprintable(char const *str)
{
    int i;

    if (my_strlen(str) == 0)
        return 1;
    for (i = 0; str[i] > '\0'; i++) {
        if ((str[i] < 0) || (str[i] > 127))
            return 0;
    }
    return 1;
}

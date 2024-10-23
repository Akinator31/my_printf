/*
** EPITECH PROJECT, 2024
** my_str_islower.c
** File description:
** task14
*/

#include "../../include/my.h"

int my_str_islower(char const *str)
{
    int i;

    if (my_strlen(str) == 0)
        return 1;
    for (i = 0; str[i] > '\0'; i++) {
        if ((str[i] < 'a') || (str[i] > 'z'))
            return 0;
    }
    return 1;
}

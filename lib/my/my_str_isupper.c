/*
** EPITECH PROJECT, 2024
** my_str_isupper.c
** File description:
** task15
*/

#include "../../include/my.h"

int my_str_isupper(char const *str)
{
    int i;

    if (my_strlen(str) == 0)
        return 1;
    for (i = 0; str[i] > '\0'; i++) {
        if ((str[i] < 'A') || (str[i] > 'Z'))
            return 0;
    }
    return 1;
}

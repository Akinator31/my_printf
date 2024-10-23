/*
** EPITECH PROJECT, 2024
** my_revstr.c
** File description:
** task03
*/

#include "../../include/my.h"

void my_swap_char(char *a, char *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

char *my_revstr(char *str)
{
    int i;

    if ((my_strlen(str) % 2) != 0) {
        for (i = 0; i <= (my_strlen(str) / 2); i++) {
            my_swap_char(&str[i], &str[my_strlen(str)] - i - 1);
        }
    } else {
        for (i = 0; i <= (my_strlen(str) / 2) - 1; i++) {
            my_swap_char(&str[i], &str[my_strlen(str)] - i - 1);
        }
    }
    return str;
}

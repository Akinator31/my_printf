/*
** EPITECH PROJECT, 2024
** my_strupcase.c
** File description:
** task08
*/

#include "../../include/my.h"

int my_strupcase(char *str)
{
    int i;
    int len = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a') && (str[i] <= 'z')) {
            my_putchar(str[i] - 32);
        }
        len += 1;
    }
    return len;
}

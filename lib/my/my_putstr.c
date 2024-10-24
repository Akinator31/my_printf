/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** task02
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    int nb_output_char = 0;

    for (str; *str != '\0'; str++) {
        my_putchar(*str);
        nb_output_char++;
    }
    return nb_output_char;
}

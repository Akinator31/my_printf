/*
** EPITECH PROJECT, 2024
** my_strcapitalize.c
** File description:
** task10
*/

#include "../../include/my.h"

void replace_unobvious_capletter(char *str)
{
    int i;

    for (i = 1; str[i] >= '\0'; i++) {
        if (((str[i - 1] < 'a') || (str[i - 1] > 'z'))) {
            continue;
        }
        if (((str[i] >= 'A') && (str[i] <= 'Z')))
            str[i] += 32;
    }
    for (i = 1; str[i] >= '\0'; i++) {
        if (((str[i - 1] < '0') || (str[i - 1] > '9'))) {
            continue;
        }
        if (((str[i] >= 'A') && (str[i] <= 'Z')))
            str[i] += 32;
    }
}

void replace_obvious_capletter(char *str)
{
    int i = 0;

    for (i; str[i] >= '\0'; i++) {
        if ((str[i] < 'a') || (str[i] > 'z')) {
            continue;
        }
        if (str[i - 1] >= 32 && str[i - 1] <= 64)
            str[i] -= 32;
    }
    for (i = 1; str[i] >= '\0'; i++) {
        if (((str[i - 1] < 'A') || (str[i - 1] > 'Z'))) {
            continue;
        }
        if (((str[i] >= 'A') && (str[i] <= 'Z')))
            str[i] += 32;
    }
}

char *my_strcapitalize(char *str)
{
    int i;

    for (i = 0; str[i] >= '\0'; i++) {
        if ((str[i] >= 97) && (str[i] <= 122)) {
            str[i] -= 32;
        }
        break;
    }
    if (my_strlen(str) == 1)
        return str;
    replace_obvious_capletter(str);
    replace_unobvious_capletter(str);
    return str;
}

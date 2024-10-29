/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** task01
*/

#include <stdlib.h>
#include "../../include/my.h"

int my_strdup(char const *src, char *dest)
{
    char *result = NULL;
    int i;

    if (dest == NULL)
        return 0;
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return 1;
}

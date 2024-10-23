/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** task01
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(char const *src)
{
    char *result = NULL;
    int i;

    result = malloc(sizeof(char) * my_strlen(src) + 1);
    if (result == NULL)
        return 0;
    for (i = 0; src[i] != '\0'; i++)
        result[i] = src[i];
    result[i] = '\0';
    return result;
}

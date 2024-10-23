/*
** EPITECH PROJECT, 2024
** my_strcpy.c
** File description:
** task01
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] > '\0'; i++) {
        dest[i] = src[i];
    }
    return dest;
}

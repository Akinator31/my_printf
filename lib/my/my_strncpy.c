/*
** EPITECH PROJECT, 2024
** my_strncpy.c
** File description:
** task02
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i <= n - 1; i++) {
        if (src[i] == '\0') {
            dest[i] = '\0';
            return dest;
        }
        dest[i] = src[i];
    }
    return dest;
}

/*
** EPITECH PROJECT, 2024
** my_strstr.c
** File description:
** task05
*/

#include <stddef.h>

static int my_len(char const *str)
{
    int size = 0;

    for (str; *str != '\0'; str++)
        size++;
    return size;
}

static int test_strstr(char *str, char const *to_find, char last_c)
{
    int i = 0;
    int f = 0;
    int finish = 0;
    int size = 0;

    for (i = 0; to_find[i] >= '\0'; i++) {
        if (str[i] == to_find[i]) {
            f = 1;
            size++;
        }
        if ((to_find[i] == last_c) && (f == 1) && (size == my_len(to_find))) {
            return 1;
        }
        if (str[i] != to_find[i]) {
            return 0;
        }
    }
    if ((f == 1) && (str[i] != to_find[i]))
        return 1;
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    int i;
    int e;

    if (my_len(to_find) == 0)
        return str;
    for (i = 0; str[i] > '\0'; i++) {
        if (test_strstr(&str[i], to_find, to_find[my_len(to_find) - 1]) == 1) {
            return &str[i];
        }
    }
    return NULL;
}

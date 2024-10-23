/*
** EPITECH PROJECT, 2024
** my_strncmp.c
** File description:
** task07
*/

#include "../../include/my.h"

void compute_value_string_1(char const *s1, char const *s2, int *s1p, int *s2p)
{
    int i;

    for (i = 0; s1[i] > '\0'; i++) {
        *s1p += s1[i];
    }
    for (i = 0; s2[i] > '\0'; i++) {
        *s2p += s2[i];
    }
}

int compute_result_1(int result_s1, int result_s2, int pos_result)
{
    if (pos_result < 0)
        return 0;
    if (result_s1 > result_s2)
        return pos_result;
    else if (result_s1 < result_s2)
        return -(int)pos_result;
    else
        return 0;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int end_compare = -1;
    int pos_result = 0;
    int result_string_1 = 0;
    int result_string_2 = 0;

    if ((my_strlen(s1) == 0) && (my_strlen(s2) == 0))
        return 0;
    while (end_compare == 0 && i <= n) {
        if (s1[i] != s2[i]) {
            pos_result = i;
            end_compare = 1;
        }
        i++;
    }
    compute_value_string_1(s1, s2, &result_string_1, &result_string_2);
    return compute_result_1(result_string_1, result_string_2, pos_result + 1);
}

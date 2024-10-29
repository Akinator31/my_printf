/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** task05
*/

#include "../../include/my.h"
#include <stdio.h>

int check_minus_and_size_number(int result, int minus, int size_nb)
{
    if ((result < -2147483648) || (result > 2147483647) || size_nb > 11)
        return 0;
    if (minus)
        return -(int)result;
    return (int)result;
}

int determine_sign_number(int minus)
{
    int k = 0;
    int p;

    if (minus > 0) {
        k = -1;
        for (p = 0; p <= minus; p++)
            k *= -1;
    }
    if (k < 0)
        minus = 1;
    else
        minus = 0;
    return minus;
}

long long get_result(int size_str, char const *str, int i)
{
    int e;
    long long result = 0;

    for (e = 0; e <= size_str; e++) {
        result += (str[i] - '0') * my_compute_power_rec(10, size_str - e - 1);
        i++;
    }
    return result;
}

void analyse_str(int **arr, char const *str, int *minus)
{
    for (*arr[3] = 0; str[*arr[3]] > '\0'; *arr[3] += 1) {
        if (str[*arr[3]] == '-' && *arr[0] <= 0) {
            *minus += 1;
            continue;
        }
        if (str[*arr[3]] == '+' && *arr[0] <= 0)
            continue;
        if (str[*arr[3]] >= '0' && str[*arr[3]] <= '9' && *arr[0] <= 0) {
            *arr[0] = 1;
            *arr[1] = *arr[3];
            continue;
        }
        if ((str[*arr[3]] < '0' || str[*arr[3]] > '9') && *arr[0] > 0) {
            *arr[2] = *arr[3];
            break;
        }
    }
}

int my_getnbr(char const *str)
{
    int minus = 0;
    int first_number_check = 0;
    int first_number_index = 0;
    int end_index = 0;
    int size_str = 0;
    int *first_nb_check_and_index[] = {&first_number_check,
        &first_number_index,
        &end_index,
        &size_str};
    long long result = 0;

    analyse_str(first_nb_check_and_index, str, &minus);
    if (!first_number_check)
        return -1;
    minus = determine_sign_number(minus);
    size_str -= first_number_index;
    result = get_result(size_str, str, first_number_index);
    return check_minus_and_size_number(result, minus, size_str);
}

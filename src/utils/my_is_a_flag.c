/*
** EPITECH PROJECT, 2024
** my_is_a_flag.c
** File description:
** my_is_a_flag function for my_printf project
*/

#include "../../include/my.h"

static const flags_t flags_arr[] = {
    {'-', 0},
    {'+', 0},
    {'#', 0},
    {' ', 0},
    {'0', 0},
    {'.', 0},
    {'?', 0}
};

int my_is_a_flag(char actual_char)
{
    int i = 0;

    for (i; flags_arr[i].flags_type != '?'; i++) {
        if (flags_arr[i].flags_type == actual_char)
            return 1;
    }
    return 0;
}

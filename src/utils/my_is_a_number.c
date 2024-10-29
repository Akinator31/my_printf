/*
** EPITECH PROJECT, 2024
** my_is_not_a_number.c
** File description:
** my_is_not_a_number function for my_printf project
*/

#include "../../include/my.h"

int my_is_a_number(char actual_char)
{
    if ((actual_char >= '0') && (actual_char <= '9'))
        return TRUE;
    return FALSE;
}

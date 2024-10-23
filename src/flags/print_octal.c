/*
** EPITECH PROJECT, 2024
** print_octal.c
** File description:
** print_octal function for my_printf project (%o)
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

long long calc_pow_8(int ptr)
{
    long long power = 1;
    
    while (power < ptr) {
        power *= 8;
    }
    return power /= 8;
}

void print_octal(va_list *list, int *nb_output_char)
{
    int pointer = (int)va_arg(*list, int);
    long long power_8 = calc_pow_8(pointer);
    long long digit = 0;
    char base[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

    while (power_8 > 0) {
        digit = get_digit(pointer, power_8);
	write(1, &base[digit], 1);
        pointer -= power_8 * digit;
	power_8 /= 8;
	*nb_output_char++;
    }
}

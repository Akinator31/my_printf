/*
** EPITECH PROJECT, 2024
** git_digit.c
** File description:
** git digit function for my_printf project
*/

int get_digit(unsigned long ptr, long long power)
{
    long long result = 0;

    while (ptr >= (power * result)) {
        result++;
    }
    return result - 1;
}

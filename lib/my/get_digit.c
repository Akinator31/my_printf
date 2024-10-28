/*
** EPITECH PROJECT, 2024
** git_digit.c
** File description:
** git digit function for my_printf project
*/

long get_digit(long ptr, long power)
{
    long result = 0;

    while (ptr >= (power * result)) {
        result++;
    }
    return result - 1;
}

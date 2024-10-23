/*
** EPITECH PROJECT, 2024
** my_swap.c
** File description:
** task01
*/

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

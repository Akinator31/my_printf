/*
** EPITECH PROJECT, 2024
** my_compute_square_root.c
** File description:
** task05
*/

int my_compute_square_root(int nb)
{
    int i = 0;

    if (nb < 0)
        return 0;
    if (nb == 1)
        return 1;
    for (i; i <= (nb / 2); i++) {
        if ((i * i) == nb)
            return i;
    }
    return 0;
}

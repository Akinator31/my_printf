/*
** EPITECH PROJECT, 2024
** my_compute_power_rec.c
** File description:
** task04
*/

int my_compute_power_rec(int nb, int p)
{
    long result = nb;

    if ((result > 2147483647) || (result < -2147483648))
        return 0;
    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    return nb * my_compute_power_rec(nb, p - 1);
}

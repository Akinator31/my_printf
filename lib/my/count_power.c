/*
** EPITECH PROJECT, 2024
** print_g_min.c
** File description:
** count_power function for my_printf project
*/

long count_power(double nb)
{
    long power = 1;

    if (nb == 0)
        return 0;
    if (nb < 0)
        nb *= -1;
    while (nb <= 1) {
        nb *= 10;
        power *= 10;
    }
    if (nb > 1) {
        while (power <= nb) {
            power *= 10;
        }
    }
    return power / 10;
}

/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** task03
*/

int my_strlen(char const *str)
{
    int size = 0;

    for (str; *str != '\0'; str++)
        size++;
    return size;
}

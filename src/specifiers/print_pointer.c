/*
** EPITECH PROJECT, 2024
** print_pointer.c
** File description:
** print_pointer function for my_printf project (%p)
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

void print_pointer(va_list *list, int *nb_output_char,
    int *index, const char *format)
{
    unsigned long pointer = (unsigned long)va_arg(*list, void *);
    int nb_char_printed = my_put_pointer(pointer);

    *nb_output_char += nb_char_printed;
    *index += 1;
}

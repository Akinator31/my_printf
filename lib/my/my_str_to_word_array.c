/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** task04
*/

#include <stdlib.h>
#include "../../include/my.h"

static int is_alphanumeric_char(char const str_char)
{
    int found = 0;

    if ((str_char >= '0') && (str_char <= '9'))
        found = 1;
    if ((str_char >= 'a') && (str_char <= 'z'))
        found = 1;
    if ((str_char >= 'A') && (str_char <= 'Z'))
        found = 1;
    return found;
}

static int next_word_index(char const *str, int index)
{
    while ((is_alphanumeric_char(str[index])) == 1 && (str[index + 1] != '\0'))
        index++;
    return index;
}

int count_word(char const *str)
{
    int nb_word = 0;
    int i;

    if (!str)
        return 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (is_alphanumeric_char(str[i]) == 1) {
            nb_word++;
            i = next_word_index(str, i);
        }
    }
    return nb_word;
}

int get_end_of_word(int star_index, char const *str)
{
    int result = star_index;

    for (star_index; (is_alphanumeric_char(str[star_index]) == 1)
        && (star_index < my_strlen(str)); star_index++)
        result++;
    return result;
}

void fill_tab(char const *str, char *char_1, int deb, int end)
{
    int i;
    int e = 0;

    for (i = deb; i <= end - 1; i++) {
        char_1[e] = str[i];
        e++;
    }
    char_1[e] = '\0';
}

char **my_str_to_word_array(char const *str)
{
    int i;
    int j = 0;
    int nb_word = 0;
    char **result = malloc(sizeof(char *) * (count_word(str) + 1));

    result[count_word(str)] = NULL;
    if (!str)
        return result;
    for (i = 0; (nb_word < count_word(str)) || (i <= my_strlen(str)); i++) {
        if (is_alphanumeric_char(str[i]) == 1) {
            j = get_end_of_word(i, str);
            result[nb_word] = malloc(sizeof(char) * (j - i) + 1);
            fill_tab(str, result[nb_word], i, j);
            nb_word += 1;
            i = next_word_index(str, i);
        }
    }
    return result;
}

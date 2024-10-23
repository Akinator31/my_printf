/*
** EPITECH PROJECT, 2024
** test_mini_printf.c
** File description:
** test for mini_printf function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, one_string_argument, .init = redirect_all_std)
{
    char str[6];
    
    my_strcpy(str, "world");
    my_printf("Hello %s\n", str);
    cr_assert_stdout_eq_str("Hello world\n");
}

Test(my_printf, multiple_argument, .init = redirect_all_std)
{
    int nb = 21;

    my_printf("If you multiple %d by %d, the result is %i.\n", nb, 2, nb * 2);
    cr_assert_stdout_eq_str("If you multiple 21 by 2, the result is 42.\n");
}

Test(my_printf, treaky_string, .init = redirect_all_std)
{
    char str[8];
    
    my_strcpy(str, "Epitech");
    my_printf("The word %%%s%% has %i characters.\n", str, my_strlen(str));
    cr_assert_stdout_eq_str("The word %Epitech% has 7 characters.\n");
}

Test(my_printf, small_big_numbers, .init = redirect_all_std)
{
    my_printf("Numbers %%%d%% and %d are so cool %d %d %d.\n", -2147483648, 2147483647, 0, -788, 790);
    cr_assert_stdout_eq_str("Numbers %-2147483648% and 2147483647 are so cool 0 -788 790.\n");
}

Test(my_printf, empty_string, .init = redirect_all_std)
{
    my_printf("");
    cr_assert_stdout_eq_str("");
}

Test(my_printf, char_only, .init = redirect_all_std)
{
    my_printf("%c", 'f');
    cr_assert_stdout_eq_str("f");
}

Test(my_printf, output_char, .init = redirect_all_std)
{
    int result = my_printf("The word Epitech has 7 characters.\n");
    cr_assert_eq(result, 35);
}

Test(my_printf, percent_at_end_of_string, .init = redirect_all_std)
{
    int result = my_printf("The word Epitech has 7 characters.\n%");
    cr_assert_eq(result, 36);
}

Test(my_printf, pointer_in_a_string, .init = redirect_all_std)
{
    int test = 45;
    my_printf("Voici un pointeur %p qui stocke l'adresse de cette variable %d\n", (void *)0x11111111, test);
    cr_assert_stdout_eq_str("Voici un pointeur 0x11111111 qui stocke l'adresse de cette variable 45\n");
}

Test(my_printf, octal, .init = redirect_all_std)
{
    int dec = 610;
    my_printf("Test convertion en octal : %o\n", dec);
    cr_assert_stdout_eq_str("Test convertion en octal : 1142\n");
}

/*
** EPITECH PROJECT, 2024
** test_mini_printf.c
** File description:
** test for mini_printf function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include <math.h>

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

Test(my_printf, octal_in_string, .init = redirect_all_std)
{
    int dec = 610;
    my_printf("Test convertion en octal : %o\n", dec);
    cr_assert_stdout_eq_str("Test convertion en octal : 1142\n");
}

Test(my_printf, unsigned_int_in_a_string, .init = redirect_all_std)
{
    my_printf("Test affichage unsigned int %u\n", 45689);
    cr_assert_stdout_eq_str("Test affichage unsigned int 45689\n");
}

Test(my_printf, hexa_min_in_string, .init = redirect_all_std)
{
    my_printf("%x", 1515);
    cr_assert_stdout_eq_str("5eb");
}

Test(my_printf, hexa_maj_in_string, .init = redirect_all_std)
{
    my_printf("%X", 1515);
    cr_assert_stdout_eq_str("5EB");
}

Test(my_printf, nb_of_char_before_the_n_flag)
{
    int result = 0;
    my_printf("Et bonjour voici un test qui compte le nombre de char avant le %n\n", &result);
    cr_assert_eq(result, 63);
}

Test(my_printf, float_min_in_a_string, .init = redirect_all_std)
{
    my_printf("Test affichage float min %f\n", 456.89);
    cr_assert_stdout_eq_str("Test affichage float min 456.890000\n");
}

Test(my_printf, float_maj_in_a_string, .init = redirect_all_std)
{
    my_printf("Test affichage float min %F\n", 456.89);
    cr_assert_stdout_eq_str("Test affichage float min 456.890000\n");
}

Test(my_printf, float_neg_in_a_string, .init = redirect_all_std)
{
    my_printf("Test affichage float min %f\n", -456.89);
    cr_assert_stdout_eq_str("Test affichage float min -456.890000\n");
}

Test(my_printf, float_INF_in_a_string, .init = redirect_all_std)
{
    double test = 1.0 / 0.0;
    my_printf("Test affichage %F\n", test);
    cr_assert_stdout_eq_str("Test affichage INF\n");
}

Test(my_printf, float_inf_in_a_string, .init = redirect_all_std)
{
    double test = 1.0 / 0.0;
    my_printf("Test affichage %f\n", test);
    cr_assert_stdout_eq_str("Test affichage inf\n");
}

Test(my_printf, scientific_write_pos_zero, .init = redirect_all_std)
{
    my_printf("%e\n", 0.215487);
    cr_assert_stdout_eq_str("2.154870e-01\n");
}

Test(my_printf, scientific_write_neg_zero, .init = redirect_all_std)
{
    my_printf("%e\n", -0.215487);
    cr_assert_stdout_eq_str("-2.154870e-01\n");
}

Test(my_printf, scientific_write_pos_upper_zero, .init = redirect_all_std)
{
    my_printf("%e\n", 21.215487);
    cr_assert_stdout_eq_str("2.121549e+01\n");
}

Test(my_printf, count_power_ten_test)
{
    long power = 9;
    int result = count_power_ten(power);
    cr_assert_eq(result, 1);
}

Test(my_printf, count_power_ten_test_2)
{
    long power = 11;
    int result = count_power_ten(power);
    cr_assert_eq(result, 2);
}

Test(my_printf, scientific_write_pos_zero_maj, .init = redirect_all_std)
{
    my_printf("%E\n", 0.215487);
    cr_assert_stdout_eq_str("2.154870E-01\n");
}

Test(my_printf, scientific_write_neg_zero_maj, .init = redirect_all_std)
{
    my_printf("%E\n", -0.215487);
    cr_assert_stdout_eq_str("-2.154870E-01\n");
}

Test(my_printf, scientific_write_pos_upper_zero_maj, .init = redirect_all_std)
{
    my_printf("%E\n", 21.215487);
    cr_assert_stdout_eq_str("2.121549E+01\n");
}

Test(my_printf, octal_neg, .init = redirect_all_std)
{
    int dec = -610;
    my_printf("%o\n", dec);
    cr_assert_stdout_eq_str("37777776636\n");
}

Test(my_printf, hexa_neg, .init = redirect_all_std)
{
    int dec = -610;
    my_printf("%x\n", dec);
    cr_assert_stdout_eq_str("fffffd9e\n");
}

Test(my_printf, hexa_maj_neg, .init = redirect_all_std)
{
    int dec = -610;
    my_printf("%X\n", dec);
    cr_assert_stdout_eq_str("FFFFFD9E\n");
}

Test(my_compute_power_rec, power_func_test)
{
    int my_func = my_compute_power_rec(4, 8);
    int result = pow(4, 8);

    cr_assert_eq(my_func, result);
}

Test(my_compute_power_rec, p_of_zero)
{
    int my_func = my_compute_power_rec(45, -8);
    int result = pow(45, -8);

    cr_assert_eq(my_func, result);
}

Test(my_printf, solo_binary_specifier, .init = redirect_all_std)
{
    my_printf("%b\n", 34);
    cr_assert_stdout_eq_str("100010\n");
}

Test(my_printf, binary_specifier_in_a_string, .init = redirect_all_std)
{
    my_printf("test : %b\n", 45);
    cr_assert_stdout_eq_str("test : 101101\n");
}

Test(count_power, 0_as_value)
{
    long test = count_power(0);
    cr_assert_eq(test, 0);
}

Test(my_get_nb_length, negative_number)
{
    int test = my_get_nb_length(-78);
    cr_assert_eq(test, 2);
}

Test(my_getnbr, classic_test)
{
    int test = my_getnbr("ce chiffre cool est 42 !");
    cr_assert_eq(test, 42);
}

Test(my_getnbr, too_large_number)
{
    int test = my_getnbr("ce chiffre : 2147483689887");
    cr_assert_eq(test, 0);
}

Test(my_getnbr, neg_number)
{
    int test = my_getnbr("ce chiffre : -7");
    cr_assert_eq(test, -7);
}

Test(my_getnbr, plus_in_a_string)
{
    int test = my_getnbr("ce ++-chiffre : +45");
    cr_assert_eq(test, -45);
}

Test(my_getnbr, empty_string_test)
{
    int test = my_getnbr("");
    cr_assert_eq(test, -1);
}

Test(my_strupcase, classic_test_str, .init = redirect_all_std)
{
    my_strupcase("salutT");
    cr_assert_stdout_eq_str("SALUT");
}

Test(my_strupcase, test_without_letter, .init = redirect_all_std)
{
    my_strupcase("");
    cr_assert_stdout_eq_str("");
}

Test(my_printf, test_flag_with_string, .init = redirect_all_std)
{
    my_printf("%-8s salut\n", "salut");
    cr_assert_stdout_eq_str("salut    salut\n");
}

Test(my_printf, test_with_neg_value_min, .init = redirect_all_std)
{
    my_printf("%e\n", 0.0);
    cr_assert_stdout_eq_str("0.000000e+00\n");
}

Test(my_printf, test_with_neg_value_maj, .init = redirect_all_std)
{
    my_printf("%E\n", 0.0);
    cr_assert_stdout_eq_str("0.000000E+00\n");
}

Test(my_printf, test_my_printf_with_S_specifier, .init = redirect_all_std)
{
    my_printf("%S\n", "salut");
    cr_assert_stdout_eq_str("SALUT\n");
}

Test(my_printf, test_str_with_zero_flag, .init = redirect_all_std)
{
    my_printf("%015s\n", "salut");
    cr_assert_stdout_eq_str("          salut\n");
}

Test(my_printf, octal_with_flag_zero, .init = redirect_all_std)
{
    my_printf("%015o\n", 34);
    cr_assert_stdout_eq_str("000000000000042\n");
}

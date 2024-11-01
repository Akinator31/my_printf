/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** task02
*/

#ifndef MY_H
    #define MY_H
    #include <stdarg.h>
    #define IS_INFINITY __builtin_inff()
    #define IS_NAN __builtin_nan("")
    #define NEG_POS_ZERO(x) __builtin_signbit (x)

enum my_printf {
    FALSE,
    TRUE,
    D,
    I,
    S,
    C,
    PERCENT,
    P,
    O,
    U,
    X_MIN,
    X_MAJ,
    N,
    F_MIN,
    F_MAJ,
    B,
    STRING,
    A
};

void my_putchar(char c);
int my_put_nbr(int nb);
int my_put_float(double nb, int is_maj);
int my_put_unsigned_nbr(unsigned int nb);
int my_put_pointer(unsigned long pointer);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_getnbr(char const *str);
int my_compute_power_rec(int nb, int p);
int my_strdup(char const *src, char *dest);
int my_get_nb_length(int nb);
int my_strupcase(char *str);
int get_next_char(const char *format, int *index);
int get_absolute_value_of_int(int nb);
int my_is_a_flag(char actual_char);
int my_is_a_specifier(char actual_char);
int my_is_good_format(char const *format, int index);
int my_is_a_number(char actual_char);
int my_float_length(double nb, int is_maj);
int flag_plus_finder(const char *format, int *index);
int flag_space_finder(const char *format, int *index);
int flag_hashtag_finder(const char *format, int *index);
int flag_zero_finder(const char *format, int *index);
int flag_minus_finder(const char *format, int *index);
int my_get_id_of_specifier(char specifier);
void apply_plus_and_space_flags_for_int_specifier(int
    flag_space, int flag_plus, int value);
void apply_good_space_for_int_specifier(int
    flag_minus, int flag_plus, int flag_space, int nb_char_printed);
void apply_minus_and_zero_flags_for_int_specifier(int
    *flags_arr[], int value);
void apply_minus_and_zero_flags_for_float_specifier(int
    **flags_arr, float value);
void apply_zero_plus_hashtag_flag(const char *format, int *index,
    int *nb_output_char, int len);
void apply_minus_flag(const char *format, int *index,
    int *nb_output_char, int len);
void apply_good_space_for_string_specifier(int
    flag_minus, int flag_plus, int flag_space, int nb_char_printed);
void apply_minus_and_zero_flags_for_string_specifier(int
    **flags_arr, char *result);
void apply_plus_and_space_flags_for_string_specifier(int
    flag_space, int flag_plus);
int my_printf(const char *restrict format, ...);
int compute(int *nb_output_char,
    const char *format, int index, va_list *list);
void print_percent(va_list *list, int *nb_output_char,
    int *index, const char *format);
void print_char(va_list *list, int *nb_output_char,
    int *index, const char *format);
void print_string(va_list *list, int *nb_output_char,
    int *index, const char *format);
void print_dec_oct_hex_integer(va_list *list, int *nb_output_char,
    int *index, const char *format);
void print_pointer(va_list *list, int *nb_output_char,
    int *index, const char *format);
void print_octal(va_list *list, int *nb_output_char,
    int *index, const char *format);
void print_unsigned_int(va_list *list, int *nb_output_char,
    int *index, const char *format);
int get_digit(unsigned long ptr, long long power);
void print_hexa_min(va_list *list, int *nb_output_char,
    int *index, const char *format);
void print_hexa_maj(va_list *list, int *nb_output_char,
    int *index, const char *format);
void get_nb_of_char(va_list *list, int *nb_output_char,
    int *index, const char *format);
void print_float_min(va_list *list, int *nb_output_char,
    int *index, const char *format);
void print_float_maj(va_list *list, int *nb_output_char,
    int *index, const char *format);
void print_e_min(va_list *list, int *nb_output_char,
    int *index, const char *format);
void print_e_maj(va_list *list, int *nb_output_char,
    int *index, const char *format);
void print_binary(va_list *list, int *nb_output_char,
    int *index, const char *format);
void print_strupcase(va_list *list, int *nb_output_char,
    int *index, const char *format);
void print_a_min(va_list *list, int *nb_output_char,
    int *index, const char *format);
long count_power(double nb);
void ten_power_write(long power, int positive,
    int maj, int *nb_output_char);
int count_power_ten(long power);

typedef struct format_specifier {
    char format_specifier;
    void (*f)(va_list *list, int *nb_output_char,
        int *index, const char *format);
    int id;
} format_specifier_t;

typedef struct flags {
    char flags_type;
    int parameter;
} flags_t;

int check_nb_of_minus_flag(const char *format, int index, flags_t **flags_arr);

#endif

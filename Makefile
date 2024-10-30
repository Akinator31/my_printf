##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_printf project
##

SRC =  lib/my/my_put_nbr.c \
       lib/my/my_put_float.c \
       lib/my/my_put_unsigned_nbr.c \
       lib/my/my_putchar.c \
       lib/my/my_put_pointer.c \
       lib/my/my_putstr.c \
       lib/my/my_strcpy.c \
       lib/my/my_strlen.c \
       lib/my/get_digit.c \
       lib/my/my_getnbr.c \
       lib/my/my_compute_power_rec.c \
       lib/my/my_strdup.c \
       lib/my/count_power.c \
       lib/my/write_e_power.c \
       lib/my/count_power_ten.c \
       lib/my/my_get_nb_length.c \
       lib/my/my_float_length.c \
       src/utils/my_is_a_flag.c \
       src/utils/my_is_a_specifier.c \
       src/utils/my_is_good_format.c \
       src/utils/my_is_a_number.c \
       src/utils/my_get_absolute_value_of_int.c \
       src/utils/my_get_next_char.c \
       my_printf.c \
       src/specifiers/print_dec_oct_hex_integer.c \
       src/specifiers/print_string.c \
       src/specifiers/print_char.c \
       src/specifiers/print_percent.c \
       src/specifiers/print_pointer.c \
       src/specifiers/print_octal.c \
       src/specifiers/print_unsigned_int.c \
       src/specifiers/print_hexa_min.c \
       src/specifiers/print_hexa_maj.c \
       src/specifiers/get_nb_of_char.c \
       src/specifiers/print_float_min.c \
       src/specifiers/print_float_maj.c \
       src/specifiers/print_e_min.c \
       src/specifiers/print_e_maj.c \
       src/flags/flags_plus.c \
       src/flags/flags_minus.c \
       src/flags/flags_space.c \
       src/flags/flags_zero.c \
       src/flags/flags_hashtag.c \
       src/flags/flags_apply.c \

OBJ = $(SRC:.c=.o)

CLEAN_DIR = src \
	src\flags \
	include \
	. \
	lib/my

NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc libmy.a $(OBJ)

test: $(NAME)
	gcc -o prog main.c -L. -lmy

test_gcovr: CFLAGS += --coverage -L. -lmy -lgcov -lcriterion
test_gcovr: $(NAME)
	gcc -o unit $(OBJ) tests/test_my_printf.c $(CFLAGS)

tests_run: unit_tests
	./unit_tests

unit_tests: CFLAGS += --coverage -L. -lmy -lgcov -lcriterion
unit_tests: fclean $(NAME)
	gcc -o unit_tests $(OBJ) tests/test_my_printf.c $(CFLAGS)

show_test: clean test_gcovr
	./unit
	gcovr -r . --html --html-details -o coverage/index.html
	firefox coverage/index.html

clean:
	rm -f lib/my/*.o
	rm -f src/flags/*.o
	rm -f src/flags/*.gcda
	rm -f src/flags/*.gcno
	rm -f src/specifiers/*.o
	rm -f src/specifiers/*.gcno
	rm -f src/specifiers/*.gcda
	rm -f *.o
	rm -f unit-*
	rm -f tests/*.gcda
	rm -f tests/*.gcno
	rm -f lib/my/*.gcda
	rm -f lib/my/*.gcno
	rm -f *.gcda
	rm -f *.gcno
	rm -f src/utils/*.o
	rm -f src/utils/*.gcda
	rm -f src/utils/*.gcno

fclean: clean

re: fclean $(NAME)

##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_printf project
##

SRC =  lib/my/my_compute_power_rec.c \
       lib/my/my_compute_square_root.c \
       lib/my/my_find_prime_sup.c \
       lib/my/my_getnbr.c \
       lib/my/my_is_prime.c \
       lib/my/my_isneg.c \
       lib/my/my_put_nbr.c \
       lib/my/my_putchar.c \
       lib/my/my_putstr.c \
       lib/my/my_revstr.c \
       lib/my/my_showmem.c \
       lib/my/my_showstr.c \
       lib/my/my_sort_int_array.c \
       lib/my/my_str_isalpha.c \
       lib/my/my_str_islower.c \
       lib/my/my_str_isnum.c \
       lib/my/my_str_isprintable.c \
       lib/my/my_str_isupper.c \
       lib/my/my_str_to_word_array.c \
       lib/my/my_strcapitalize.c \
       lib/my/my_strcat.c \
       lib/my/my_strcmp.c \
       lib/my/my_strcpy.c \
       lib/my/my_strdup.c \
       lib/my/my_strlen.c \
       lib/my/my_strlowcase.c \
       lib/my/my_strncat.c \
       lib/my/my_strncmp.c \
       lib/my/my_strncpy.c \
       lib/my/my_strstr.c \
       lib/my/my_strupcase.c \
       lib/my/my_swap.c \
       my_printf.c \
       src/flags/print_dec_oct_hex_integer.c \
       src/flags/print_string.c \
       src/flags/print_char.c \
       src/flags/print_percent.c \
       src/flags/print_pointer.c \

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc libmy.a $(OBJ)

test: $(NAME)
	gcc -o prog main.c -L. -lmy

test_run: CFLAGS += --coverage
test_run: $(NAME)
	gcc -o unit $(OBJ) tests/test_my_printf.c -L. -lmy -lgcov -lcriterion $(CFLAGS)

show_test:
	gcovr -r . --html --html-details -o coverage/index.html
	firefox coverage/index.html

clean:
	rm -f lib/my/*.o
	rm -f src/flags/*.o
	rm -f *.o
	rm -f prog
	rm -f libmy.a
	rm -f unit-*
	rm -f unit
	rm -f tests/*.gcda
	rm -f tests/*.gcno
	rm -f lib/my/*.gcda
	rm -f lib/my/*.gcno

fclean: clean

re: fclean all

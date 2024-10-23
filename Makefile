##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_printf project
##

SRC =  lib/my/my_put_nbr.c \
       lib/my/my_putchar.c \
       lib/my/my_putstr.c \
       lib/my/my_strcpy.c \
       lib/my/my_strlen.c \
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

show_test: test_run
	./unit
	gcovr -r . --html --html-details -o coverage/index.html
	firefox coverage/index.html

clean:
	rm -f lib/my/*.o
	rm -f src/flags/*.o
	rm -f src/flags/*.gcda
	rm -f src/flags/*.gcno
	rm -f *.o
	rm -f prog
	rm -f libmy.a
	rm -f unit-*
	rm -f unit
	rm -f tests/*.gcda
	rm -f tests/*.gcno
	rm -f lib/my/*.gcda
	rm -f lib/my/*.gcno
	rm -f *.gcda
	rm -f *.gcno
	mr_clean
	mr_clean src
	mr_clean src/flags
	mr_clean include
	mr_clean lib/my

fclean: clean

re: fclean all

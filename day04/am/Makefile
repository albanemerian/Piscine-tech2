##
## EPITECH PROJECT, 2025
## day4
## File description:
## Makefile
##

## Makefile
##

CC = gcc
CFLAGS = -std=gnu17 -Wall -Wextra -Iinclude --coverage
LDFLAGS = -lcriterion -lgcov

SRC		=	ex01/mul_div.c	\
			ex02/concat.c	\
			ex03/array_1d_to_2d.c	\
			ex04/print.c	\
			ex05/disp.c		\
			ex05/sort.c	\
			ex05/uniq.c


OBJ = $(SRC:.c=.o)

TEST_SRC	=	tests/tests_mul_div.c	\
				tests/tests_concat.c	\
				tests/tests_array_1d_to_2d.c


TEST_OBJ = $(TEST_SRC:.c=.o)
EXEC = my_program
TEST_EXEC = unit_tests

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

tests_run: CFLAGS += -g
tests_run: $(OBJ) $(TEST_OBJ)
	$(CC) -o $(TEST_EXEC) $^ $(LDFLAGS)
	@./$(TEST_EXEC)
	@gcovr --exclude tests/

clean:
	rm -f $(OBJ) $(TEST_OBJ)

fclean: clean
	rm -f $(EXEC) $(TEST_EXEC) *.gcda *.gcno
	cd tests && rm -f *.gcda *.gcno
	rm -f ex01/*.gcda ex01/*.gcno ex02/*.gcda ex02/*.gcno ex03/*.gcda ex03/*.gcno ex04/*.gcda ex04/*.gcno ex05/*.gcda ex05/*.gcno

re: fclean all

.PHONY: all tests_run clean fclean re

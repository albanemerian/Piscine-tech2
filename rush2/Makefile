##
## EPITECH PROJECT, 2025
## rush02
## File description:
## Makefile
##

SRC	=	player.c \
		point.c \
		vertex.c \
		new.c \
		float.c \
		int.c \
		char.c \

TEST_SRC =	tests/tests_player.c \
			tests/tests_point.c \
			tests/tests_vertex.c \
			tests/tests_new.c \
			tests/tests_int.c \
			tests/tests_float.c \
			tests/tests_char.c \

TEST_NAME =	unit_tests

TEST_FLAGS	=	--coverage -lcriterion

CFLAGS	+= -std=gnu17 -Wall -Wextra

C_STYLE	=	coding-style-reports.log

all:

unit_tests:	$(SRC) $(TEST_SRC)
	gcc -o $(TEST_NAME) $(SRC) $(TEST_SRC) $(CFLAGS) $(TEST_FLAGS)
	./unit_tests

tests_run:	unit_tests
	./$(TEST_NAME)

clean:
	rm -rf *.o
	rm -rf *.gc*

fclean: clean
	rm -f $(TEST_NAME)
	rm -rf $(C_STYLE)

coverage: tests_run
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

##
## EPITECH PROJECT, 2025
## test-rush
## File description:
## Makefile
##

CC	=	gcc

NAME	=	z

UNIT_TEST	= test

CFLAGS	=	-g -Wshadow -Werror -Wall -I./include


SRC		=   z.c

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)
			@echo -e "\e[1;32m{ Makefile is ready }\e[00;37m"
			@echo -e "\e[1;36m{ Binary is ready }\e[00;37m"

clean:
			@rm -f $(OBJ)
			@rm -f *.gc*
			@rm -f coding-style-reports.log
			@rm -f *~
			@rm -f *.gcda
			@rm -f *.gcno
			@rm -f z


fclean:	clean
			@rm -f $(NAME)
			@rm -f $(UNIT_TEST)
			@echo -e "\e[1;33m{ REPOSITORIE as been cleaned }\e[00;37m"

norm:
	@make clean
	@make fclean
	@coding-style . .
	@cat coding-style-reports.log

re:	fclean all

##
## EPITECH PROJECT, 2025
## B-PDG-300-NAN-3-1-PDGD05-albane.merian
## File description:
## Makefile
##

SRC =	string_one.c	\
		string_two.c	\
		string_three.c	\
		string_four.c	\
		string_five.c	\
		string_six.c	\
		string_seven.c	\
		string_eight.c	\
		string_nine.c	\
		string_ten.c	\
		string_eleven.c	\
		string_twelve.c	\
		string_thriteen.c	\
		string_fourteen.c

OBJ = $(SRC:.c=.o)

NAME =  libstring.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	@echo -e "\e[1;33m{ Library is ready }\e[00;37m"

clean:
	rm -f $(OBJ)
	rm -f *.c~ $(OBJ)
	rm -f *.o $(OBJ)
	rm -f libstring.a
	@echo -e "\e[1;33m{ Library as been cleaned }\e[00;37m"

fclean: clean
	rm -f $(NAME)
	@echo -e "\e[1;31m{ Cleaned up binary and library }\e[00;37m"

re: fclean all

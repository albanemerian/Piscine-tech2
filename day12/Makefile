##
## EPITECH PROJECT, 2025
## B-PDG-300-NAN-3-1-PDGD12-albane.merian
## File description:
## Makefile
##

SRC	=	ex06/Toy.cpp	\
		ex06/Woody.cpp	\
		ex06/Buzz.cpp	\
		ex06/Picture.cpp	\
		ex06/ToyStory.cpp 


TEST_SRC =	tests/test_ex06.cpp


TEST_NAME =	unit_tests

TEST_FLAGS	=	--coverage -lcriterion

CFLAGS	+= -Wall -Wextra

C_STYLE	=	coding-style-reports.log



all:
	g++ -o $(TEST_NAME) $(SRC) $(TEST_SRC) $(CFLAGS) $(TEST_FLAGS)
	./unit_tests

unit_tests:	$(SRC) $(TEST_SRC)
	g++ -o $(TEST_NAME) $(SRC) $(TEST_SRC) $(CFLAGS) $(TEST_FLAGS)
	./unit_tests

re: fclean all
	g++ -o $(TEST_NAME) $(SRC) $(TEST_SRC) $(CFLAGS) $(TEST_FLAGS)
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

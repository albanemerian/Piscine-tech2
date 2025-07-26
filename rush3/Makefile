##
## EPITECH PROJECT, 2025
## MyGKrellm
## File description:
## Makefile
##

GREEN = \033[0;32m
PURPLE = \033[0;34m
RESET = \033[0m

SRC	=	src/main.cpp \
		src/Krell.cpp \
		src/Module/AModule.cpp \
		src/Module/DateTime.cpp \
		src/Module/CpuModule.cpp \
		src/Module/HostModule.cpp \
		src/Module/RamModule.cpp \
		src/Module/BatteryModule.cpp \
		src/Module/TemperatureModule.cpp \
		src/Module/NetworkModule.cpp \
		src/Module/DiskModule.cpp \
		src/Module/ProcModule.cpp \
		src/GraphicalComponent/ADisplay.cpp \
		src/GraphicalComponent/Graph.cpp \
		src/GraphicalComponent/Dial.cpp \
		src/GraphicalComponent/Text.cpp \
		src/GraphicalComponent/Box.cpp \
		src/GraphicalComponent/Bar.cpp

SRCT =	src/Module/DateTime.cpp     		\
		src/Krell.cpp \
		src/Module/AModule.cpp \
		src/Module/BatteryModule.cpp     	\
		src/Module/CpuModule.cpp     		\
		src/Module/HostModule.cpp \
		src/Module/RamModule.cpp \
		src/Module/TemperatureModule.cpp \
		src/Module/NetworkModule.cpp \
		src/Module/DiskModule.cpp \
		src/Module/ProcModule.cpp \
		src/GraphicalComponent/ADisplay.cpp \
		src/GraphicalComponent/Graph.cpp \
		src/GraphicalComponent/Dial.cpp \
		src/GraphicalComponent/Text.cpp \
		src/GraphicalComponent/Box.cpp \
		src/GraphicalComponent/Bar.cpp

TEST_SRC =	tests/test_main.cpp			\
			tests/TestDateTime.cpp		\

NAME	=	MyGKrellm

TEST_NAME =	unit_tests

TEST_FLAGS	=	--coverage -lcriterion

CFLAGS	+= -std=c++20 -Wall -Wextra

SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

LDFLAGS = -lncurses $(SFML_FLAGS)

C_STYLE	=	coding-style-reports.log

all:
	@for file in $(SRC); do \
		echo -e "$(GREEN){✓} $${file#src/}$(RESET)"; \
		g++ -c $$file $(CFLAGS); \
	done
	@g++ -o $(NAME) *.o $(LDFLAGS)
	@rm -f *.o

unit_tests:	fclean
	@g++ -o $(TEST_NAME) $(SRCT) $(TEST_SRC) $(LDFLAGS) $(TEST_FLAGS)

re: fclean all
	@for file in $(SRC); do \
		echo -e "$(PURPLE){✓} $${file#src/}$(RESET)"; \
		g++ -c $$file $(CFLAGS); \
	done
	@g++ -o $(NAME) *.o $(LDFLAGS)
	@rm -f *.o

tests_run:	unit_tests
	@./$(TEST_NAME)

clean:
	@rm -rf *.o
	@rm -rf *.gc*
	@rm -rf coding-style-reports.log

fclean: clean
	@rm -f $(TEST_NAME)
	@rm -rf $(C_STYLE)

coverage: tests_run
	@gcovr --exclude tests/
	@gcovr --exclude tests/ --branch

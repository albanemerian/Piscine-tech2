##
## EPITECH PROJECT, 2025
## B-PDG-300-NAN-3-1-PDGD06-albane.merian
## File description:
## Makefile
##

# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror

# Source files
SRCS = MyCat.cpp
# Object files
OBJS = $(SRCS:.cpp=.o)
# Executable name
EXEC = MyCat

# Deault target
all: $(EXEC)

# Rule to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
			@rm -f $(OBJ)
			@rm -f *.gc*
			@rm -f coding-style-reports.log
			@rm -f *~
			@rm -f *.gcda
			@rm -f *.gcno
			@rm -f z

fclean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
re: fclean all

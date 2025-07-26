##
## EPITECH PROJECT, 2025
## B-PDG-300-NAN-3-1-PDGD02-albane.merian
## File description:
## Makefile
##


SRC = DoOp.hs
OUT = doop
GHC = ghc
UNIT = unit-tests

all: $(OUT)

$(OUT): $(SRC)
	$(GHC) -o $(OUT) $(SRC)

clean:
	rm -f *.hi *.o

fclean: clean
	rm -f $(OUT)

re: fclean all

norm:
	rm -f *.hi *.o
	rm -f $(OUT)
	coding-style . .
	cat coding-style-reports.log

tests_run: fclean
	stack test --coverage
	mkdir -p test/coverage
	mv .stack-work/install/*/*/*/hpc/test/$(UNIT)/*.tix \
	test/coverage


##
## EPITECH PROJECT, 2025
## B-PDG-300-NAN-3-1-PDGRUSH1-albane.merian
## File description:
## Makefile
##


SRC = 	Main.hs 				\
		Pushswap.hs

OUT = pushswap
GHC = ghc
UNIT = unit-tests
PNAME = rush1
COVLOC = .stack-work/install/*/*/*/hpc/$(PNAME)/$(UNIT)/*.tix


all: $(OUT)

$(OUT): $(SRC)
	$(GHC) -o $(OUT) $(SRC)

clean:
	rm -f *.hi *.o

fclean: clean
	rm -f $(OUT)
	rm -f coding-style-reports.log

re: fclean all

norm:
	rm -f *.hi *.o
	rm -f $(OUT)
	coding-style . .
	cat coding-style-reports.log

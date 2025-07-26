##
## EPITECH PROJECT, 2025
## B-PDG-300-NAN-3-1-PDGD03-albane.merian
## File description:
## Makefile
##


SRC = Tree.hs
OUT = tree
GHC = ghc


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

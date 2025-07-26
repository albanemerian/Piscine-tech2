{-
-- EPITECH PROJECT, 2025
-- B-PDG-300-NAN-3-1-PDGRUSH1-albane.merian
-- File description:
-- main
-}

module Pushswap where

import System.Exit (exitWith, ExitCode(..))

switch :: [a] -> [a]
switch (a:b:as) = b : a : as
switch as = as 

rotate :: [a] -> [a]
rotate [] = []
rotate [a] = [a]
rotate (a:as) = as ++ [a]

reverseRotate :: [a] -> [a]
reverseRotate [] = []
reverseRotate [a] = [a]
reverseRotate as = last as : init as 

sa :: ([a], [a]) -> ([a], [a])
sa (as, bs) = (switch as, bs)

sb :: ([a], [a]) -> ([a], [a])
sb (as, bs) = (as, switch bs)

sc :: ([a], [a]) -> ([a], [a])
sc (as, bs) = (switch as, switch bs)

ra :: ([a], [a]) -> ([a], [a])
ra (as, bs) = (rotate as, bs)

rb :: ([a], [a]) -> ([a], [a])
rb (as, bs) = (as, rotate bs)

rr :: ([a], [a]) -> ([a], [a])
rr (as, bs) = (rotate as, rotate bs)

rra :: ([a], [a]) -> ([a], [a])
rra (as, bs) = (reverseRotate as, bs)

rrb :: ([a], [a]) -> ([a], [a])
rrb (as, bs) = (as, reverseRotate bs)

rrr :: ([a], [a]) -> ([a], [a])
rrr (as, bs) = (reverseRotate as, reverseRotate bs)

pa :: ([a], [a]) -> ([a], [a])
pa (as, (b:bs)) = (b:as, bs)
pa (as, bs) = (as, bs)

pb :: ([a], [a]) -> ([a], [a])
pb ((a:as), bs) = (as, (a:bs))
pb (as, bs) = (as, bs)

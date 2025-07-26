{-
-- EPITECH PROJECT, 2025
-- B-PDG-300-NAN-3-1-PDGRUSH1-albane.merian
-- File description:
-- handler
-}

module HandlEr where

import System.Exit (exitWith, ExitCode(..))
import Pushswap

data Tree a = Empty | Node (Tree a) a (Tree a)
    deriving (Show)

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree a Empty = Node Empty a Empty
addInTree a (Node left v right)
    | a < v  = Node (addInTree a left) v right
    | otherwise = Node left v (addInTree a right)

myAp :: [a] -> [a] -> [a]
myAp [] ys = ys
myAp (x:xs) ys = x : myAp xs ys

listToTree :: Ord a => [a] -> Tree a
listToTree [] = Empty
listToTree (x:xs) = addInTree x (listToTree xs)

treeToList :: Ord a => Tree a -> [a]
treeToList Empty = []
treeToList (Node l val r) =  myAp (myAp (treeToList l) [val]) (treeToList r)

creatSortedList :: Ord a => [a] -> [String] -> [a]
creatSortedList [] [] = []
creatSortedList array _ = treeToList (listToTree array)

valFlag :: [String]
valFlag = ["sa", "sb", "sc", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"]

doOperations :: ([a], [a]) -> [String] -> ([a], [a])
doOperations (n, b) ("sa":fs) = doOperations (sa (n, b)) fs
doOperations (n, b) ("sb":fs) = doOperations (sb (n, b)) fs
doOperations (n, b) ("sc":fs) = doOperations (sc (n, b)) fs
doOperations (n, b) ("pa":fs) = doOperations (pa (n, b)) fs
doOperations (n, b) ("pb":fs) = doOperations (pb (n, b)) fs
doOperations (n, b) ("ra":fs) = doOperations (ra (n, b)) fs
doOperations (n, b) ("rb":fs) = doOperations (rb (n, b)) fs
doOperations (n, b) ("rr":fs) = doOperations (rr (n, b)) fs
doOperations (n, b) ("rra":fs) = doOperations (rra (n, b)) fs
doOperations (n, b) ("rrb":fs) = doOperations (rrb (n, b)) fs
doOperations (n, b) ("rrr":fs) = doOperations (rrr (n, b)) fs
doOperations (n, b) _ = (n, b)

getLineInput :: [Int] -> IO ()
getLineInput n = do
    line <- getLine
    let temp_list = creatSortedList n (words line)
    let newN = doOperations (n, []) (words line)
    case all (`elem` valFlag) (words line) of
        False -> exitWith (ExitFailure 84)
        True  -> putStrLn $ if fst newN == temp_list
                               then "OK"
                               else "KO: " ++ show newN
    return ()

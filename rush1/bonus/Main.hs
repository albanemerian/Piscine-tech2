{-
-- EPITECH PROJECT, 2025
-- B-PDG-300-NAN-3-1-PDGRUSH1-albane.merian
-- File description:
-- main
-}

import System.Environment (getArgs)
import System.Exit (exitWith, ExitCode(..))
import Text.Read (readMaybe)
import Pushswap

data Tree a = Empty | Node (Tree a) a (Tree a)
    deriving (Eq)

-- Sorting functions

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree a Empty = Node Empty a Empty
addInTree a (Node left v right)
    | a < v  = Node (addInTree a left) v right
    | otherwise = Node left v (addInTree a right)

listToTree :: Ord a => [a] -> Tree a
listToTree [] = Empty
listToTree (a:as) = addInTree a (listToTree as)

treeToList :: Ord a => Tree a -> [a]
treeToList Empty = []
treeToList (Node left a right) = treeToList left ++ [a] ++ treeToList right

treeSort :: (Show a, Ord a) => [a] -> [a]
treeSort a = treeToList (listToTree a)

-- Pushswap

findIndexOfSmallest :: [Int] -> Int
findIndexOfSmallest xs = snd $ minimum $ zip xs [0..]

algoSort :: ([Int],[Int]) -> [String]
algoSort ([], _) = []
algoSort (as, bs) = do
    let index = findIndexOfSmallest as
        in case index of
            0 -> "pb" : algoSort (pb (as, bs))
            1 -> "sa" : algoSort (sa (as, bs))
            _ -> if index > (div (length as) 2)
                then "rra" : algoSort (rra (as, bs))
                else "ra" : algoSort (ra (as, bs))

sendInListA :: ([Int],[Int]) -> [String]
sendInListA (_, []) = []
sendInListA (as, bs) = "pa" : sendInListA (pa (as, bs)) 

pushswap :: [Int] -> IO ()
pushswap [] = exitWith (ExitFailure 84)
pushswap as = do
    let cmd = algoSort (as, [])
    putStrLn $ show (cmd ++ replicate (length as) "pa")
    putStrLn $ show (treeSort as)
    return ()

isNum :: String -> Bool
isNum s = case readMaybe s :: Maybe Int of
    Just _ -> True
    Nothing -> False

main :: IO ()
main = do
    args <- getArgs
    case () of
        _ | length args < 1 -> exitWith (ExitFailure 84)
          | all isNum args  -> pushswap (map read args :: [Int])
          | otherwise       -> exitWith (ExitFailure 84)

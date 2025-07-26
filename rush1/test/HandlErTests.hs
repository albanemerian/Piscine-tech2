{-
-- EPITECH PROJECT, 2025
-- B-PDG-300-NAN-3-1-PDGRUSH1-albane.merian
-- File description:
-- main
-}

module HandlErTests where

import Test.HUnit
import HandlEr

testShowEmpty = TestCase (assertEqual "Show Empty" "Empty" (show (Empty :: Tree Int)))
testShowNode = TestCase (assertEqual "Show Node" "Node Empty 42 Empty" (show (Node Empty 42 Empty :: Tree Int)))

testTreeToList = TestCase (assertEqual "Tree to list" (treeToList (Node (Node Empty (-2) (Node (Node (Node Empty 1 Empty) 2 Empty) 3 (Node (Node Empty 5 Empty) 6 Empty))) 9 Empty)) ([-2,1,2,3,5,6,9]))
testEmptyTreeToList = TestCase (assertEqual "Empty tree to list" (treeToList (Empty :: Tree Int)) [])

testCreateSortedListEmptyInput = TestCase (assertEqual "Empty input lists" (creatSortedList ([] :: [Int]) ([] :: [String])) ([] :: [Int]))
testCreateSortedList = TestCase (assertEqual "Create sorted list" (creatSortedList [3, 1, 2] []) [1, 2, 3])

testMyAppend = TestCase (assertEqual "Test my Append" (myAp [1,2,3] [4,5,6]) [1,2,3,4,5,6])

testValFlag = TestCase (assertEqual "Test valFlag" valFlag ["sa", "sb", "sc", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"])

testDoOperations = TestCase (assertEqual "Test doOperations" (doOperations ([1,2,3], [4,5,6]) ["sa", "sb", "sc", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"]) ([1,2,3], [4,5,6]))

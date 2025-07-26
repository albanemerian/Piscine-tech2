{-
-- EPITECH PROJECT, 2025
-- B-PDG-300-NAN-3-1-PDGRUSH1-albane.merian
-- File description:
-- main
-}

module PushswapTests where

import Test.HUnit
import Pushswap

testSwitchEmpty = TestCase (assertEqual "Switch Empty" (switch ([] :: [Int])) ([] :: [Int]))
testRotateEmpty = TestCase (assertEqual "Rotate Empty" (rotate ([] :: [Int])) ([] :: [Int]))
testReverseRotateEmpty = TestCase (assertEqual "Reverse Rotate Empty" (reverseRotate ([] :: [Int])) ([] :: [Int]))

testSwitchA = TestCase (assertEqual "Switch list A" (sa ([1,2,3],[])) ([2,1,3],[]))
testSwitchB = TestCase (assertEqual "Switch list B" (sb ([],[1,2,3])) ([],[2,1,3]))
testSwitchC = TestCase (assertEqual "Switch list C" (sc ([1,2,3],[1,2,3])) ([2,1,3],[2,1,3]))
testSwitchSimpleA = TestCase (assertEqual "Switch list A with 1 element" (sa ([],[1])) ([],[1]))
testSwitchSimpleB = TestCase (assertEqual "Switch list B with 1 element" (sb ([1],[])) ([1],[]))
testSwitchSimpleC = TestCase (assertEqual "Switch list C with 1 element" (sc ([1],[1])) ([1],[1]))

testRotateA = TestCase (assertEqual "Rotate list A" (ra ([1,2,3],[])) ([2,3,1],[]))
testRotateB = TestCase (assertEqual "Rotate list B" (rb ([],[1,2,3])) ([],[2,3,1]))
testRotateC = TestCase (assertEqual "Rotate list C" (rr ([1,2,3],[1,2,3])) ([2,3,1],[2,3,1]))
testRotateSimpleA = TestCase (assertEqual "Rotate list A with 1 element" (ra ([1],[])) ([1],[]))
testRotateSimpleB = TestCase (assertEqual "Rotate list B with 1 element" (rb ([],[1])) ([],[1]))
testRotateSimpleC = TestCase (assertEqual "Rotate list C with 1 element" (rr ([1],[1])) ([1],[1]))

testReverseRotateA = TestCase (assertEqual "Reverse Rotate list A" (rra ([1,2,3],[])) ([3,1,2],[]))
testReverseRotateB = TestCase (assertEqual "Reverse Rotate list B" (rrb ([],[1,2,3])) ([],[3,1,2]))
testReverseRotateC = TestCase (assertEqual "Reverse Rotate list C" (rrr ([1,2,3],[1,2,3])) ([3,1,2],[3,1,2]))
testReverseRotateSimpleA = TestCase (assertEqual "Reverse Rotate list A with 1 element" (rra ([1],[])) ([1],[]))
testReverseRotateSimpleB = TestCase (assertEqual "Reverse Rotate list B with 1 element" (rrb ([],[1])) ([],[1]))
testReverseRotateSimpleC = TestCase (assertEqual "Reverse Rotate list C with 1 element" (rrr ([1],[1])) ([1],[1]))

testJumpEmptyA = TestCase (assertEqual "Jump in empty list A" (pa ([],[1,2,3])) ([1],[2,3]))
testJumpA = TestCase (assertEqual "Jump list A" (pa ([4,5,6],[1,2,3])) ([1,4,5,6],[2,3]))
testJumpAEmptyB = TestCase (assertEqual "Jump list A with empty B" (pa ([1,2,3],[])) ([1,2,3],[]))

testJumpEmptyB = TestCase (assertEqual "Jump in empty list B" (pb ([1,2,3],[])) ([2,3],[1]))
testJumpB = TestCase (assertEqual "Jump list B" (pb ([4,5,6],[1,2,3])) ([5,6],[4,1,2,3]))
testJumpBEmptyA = TestCase (assertEqual "Jump list B with empty A" (pb ([],[1,2,3])) ([],[1,2,3]))

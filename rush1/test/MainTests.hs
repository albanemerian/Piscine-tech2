{-
-- EPITECH PROJECT, 2025
-- B-PDG-300-NAN-3-1-PDGRUSH1-albane.merian
-- File description:
-- main
-}

import Test.HUnit
import PushswapTests
import HandlErTests

tests :: Test
tests = TestList [
        TestLabel "Switch Empty" testSwitchEmpty,
        TestLabel "Rotate Empty" testRotateEmpty,
        TestLabel "Reverse Rotate Empty" testReverseRotateEmpty,
        TestLabel "Switch list A" testSwitchA,
        TestLabel "Switch list B" testSwitchB,
        TestLabel "Switch list C" testSwitchC,
        TestLabel "Switch list A with 1 element" testSwitchSimpleA,
        TestLabel "Switch list B with 1 element" testSwitchSimpleB,
        TestLabel "Switch list C with 1 element" testSwitchSimpleC,
        TestLabel "Rotate list A" testRotateA,
        TestLabel "Rotate list B" testRotateB,
        TestLabel "Rotate list C" testRotateC,
        TestLabel "Rotate list A with 1 Element" testRotateSimpleA,
        TestLabel "Rotate list B with 1 Element" testRotateSimpleB,
        TestLabel "Rotate list C with 1 Element" testRotateSimpleC,
        TestLabel "Reverse Rotate list A" testReverseRotateA,
        TestLabel "Reverse Rotate list B" testReverseRotateB,
        TestLabel "Reverse Rotate list C" testReverseRotateC,
        TestLabel "Reverse Rotate list A with 1 Element" testReverseRotateSimpleA,
        TestLabel "Reverse Rotate list B with 1 Element" testReverseRotateSimpleB,
        TestLabel "Reverse Rotate list C with 1 Element" testReverseRotateSimpleC,
        TestLabel "Jump in empty List A" testJumpEmptyA,
        TestLabel "Jump List A" testJumpA,
        TestLabel "Jump List A with empty B" testJumpAEmptyB,
        TestLabel "Jump in empty List B" testJumpEmptyB,
        TestLabel "Jump List B" testJumpB,
        TestLabel "Jump List B with empty A" testJumpBEmptyA,
        TestLabel "Show Empty" testShowEmpty,
        TestLabel "Show Node" testShowNode,
        TestLabel "Tree to List" testTreeToList,
        TestLabel "Empty Tree to List" testEmptyTreeToList,
        TestLabel "Create Sorted List" testCreateSortedList,
        TestLabel "Empty Input Line" testCreateSortedListEmptyInput,
        TestLabel "Test my Append" testMyAppend,
        TestLabel "Test valFlag" testValFlag,
        TestLabel "Test doOperations" testDoOperations
    ]

main :: IO ()
main = do
    counts <- runTestTT tests
    if errors counts + failures counts == 0
        then putStrLn "All tests passed!"
        else putStrLn "Some tests has failed."

--h spec a regarder

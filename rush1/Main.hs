{-
-- EPITECH PROJECT, 2025
-- B-PDG-300-NAN-3-1-PDGRUSH1-albane.merian
-- File description:
-- main
-}

import System.Environment (getArgs)
import System.Exit (exitWith, ExitCode(..))
import HandlEr
import Text.Read (readMaybe)

isNum :: String -> Bool
isNum s = case readMaybe s :: Maybe Int of
    Just _ -> True
    Nothing -> False

main :: IO ()
main = do
    args <- getArgs
    case () of
        _ | length args < 1 -> exitWith (ExitFailure 84)
          | all isNum args  -> getLineInput (map read args :: [Int])
          | otherwise       -> exitWith (ExitFailure 84)

{-
-- EPITECH PROJECT, 2025
-- B-PDG-300-NAN-3-1-PDGD02-albane.merian
-- File description:
-- DoOp
-}

module DoOp where
  
import System.Environment (getArgs)
import System.Exit (exitWith, ExitCode(..))

myElem :: Eq a => a -> [a] -> Bool
myElem _ [] = False
myElem x (y:ys) = if x == y then True else myElem x ys

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv x y = Just (x `div` y)

safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth (x:xs) n = if n == 0 then Just x else safeNth xs (n - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just x) = Just (x + 1)

myLookup :: Eq a => a -> [(a , b)] -> Maybe b
myLookup _ [] = Nothing
myLookup x ((y, z): ys) = if x == y then Just z else myLookup x ys

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo _ Nothing _ = Nothing
maybeDo _ _ Nothing = Nothing
maybeDo f (Just a) (Just b) = Just (f a b)


readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt ('-':str)
  | all (\c -> myElem c ['0'..'9']) str = Just (read ('-':str))
  | otherwise = Nothing
readInt str
  | all (\c -> myElem c ['0'..'9']) str = Just (read str)
  | otherwise = Nothing

getLineLength :: IO Int
getLineLength = do
  line <- getLine
  return (length line)

printAndGetLength :: String -> IO Int
printAndGetLength str = putStrLn str >>
  return (length str)

printMiddleLines :: String -> Int -> IO ()
printMiddleLines _ 0 = return ()
printMiddleLines line n = putStrLn line >>
  printMiddleLines line (n - 1)

printBox :: Int -> IO ()
printBox 0 = return ()
printBox 1 = putStrLn ("++")
printBox n
  | n < 0 = return ()
printBox n = putStrLn ("+" ++ replicate (new) '-' ++ "+") >>
  printMiddleLines midlle_line temp >>
  putStrLn ("+" ++ replicate (new) '-' ++ "+")
  where new  = (n * 2) - 2
        temp = n - 2
        midlle_line = ("|" ++ replicate (new) ' ' ++ "|")

concatLines :: Int -> IO String
concatLines 0 = return ""
concatLines n 
  | n < 0 = return ""
concatLines n = do
  line <- getLine
  nextLines <- concatLines (n - 1)
  return (line ++ nextLines)

getInt :: IO (Maybe Int)
getInt = do
  line <- getLine
  return (readInt line)


-- doOp :: Maybe Int -> Char -> Maybe Int -> IO ()
-- doOp _ b _ 
--   | not (b `myElem` ['+', '-', '*', '/', '%']) = exitWith (ExitFailure 84)
-- doOp (Just a) b (Just c) = 
--   let result = case b of
--         '+' -> a + c
--         '-' -> a - c
--         '*' -> a * c
--         '/' -> if c == 0 then exitWith (ExitFailure 84) else a `div` c
--         '%' -> if c == 0 then exitWith (ExitFailure 84) else a `mod` c
--   in print result

doOp :: Maybe Int -> Char -> Maybe Int -> IO ()
doOp _ b _ 
  | not (b `myElem` ['+', '-', '*', '/', '%']) = exitWith (ExitFailure 84)
doOp (Just a) '/' (Just 0) = exitWith (ExitFailure 84)
doOp (Just a) '%' (Just 0) = exitWith (ExitFailure 84)
doOp (Just a) b (Just c) =
  let result = case b of
        '+' -> a + c
        '-' -> a - c
        '*' -> a * c
        '/' -> a `div` c
        '%' -> a `mod` c
  in print result
doOp _ _ _ = exitWith (ExitFailure 84)

temp :: Maybe Int -> Char -> Maybe Int -> IO ()
temp a b c = do
  args <- getArgs
  if length (args !! 1) /= 1
    then exitWith (ExitFailure 84)
    else doOp a b c

main :: IO ()
main = do
    args <- getArgs
    if length args /= 3
      then exitWith (ExitFailure 84)
      else let
        a = readInt (args !! 0)
        b = head (args !! 1)
        c = readInt (args !! 2)
      in temp a b c 


-- main :: IO ()
-- main = do
--     args <- getArgs
--     if length(args) /= 3
--       then exitWith (ExitFailure 84)
--       else doOp a b c >>
--       exitWith ExitSuccess
--       where a = args !! 0
--             b = args !! 1
--             c = args !! 2
--if b is in ['+', '-', '*', '/', '%'] 

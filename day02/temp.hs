{-
-- EPITECH PROJECT, 2025
-- B-PDG-300-NAN-3-1-PDGD02-albane.merian
-- File description:
-- temp
-}


myAdd :: Maybe Int -> Maybe Int -> Maybe Int
myAdd (Just x) (Just y) = Just (x + y)
myAdd _ _ = Nothing

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv x y = Just (x `div` y)

safeSqrt :: Int -> Maybe Int
safeSqrt x
  | x < 0 = Nothing
  | otherwise = Just (floor (sqrt (fromIntegral x)))

safeSucc :: Int -> Maybe Int
safeSucc 0 = Nothing
safeSucc x = Just (x + 1)

main :: IO ()
main = do
    putStrLn "Please enter a line:"
    line <- getLine
    putStrLn ("You entered: " ++ line)

  -- mapM_ (\_ -> putStrLn midlle_line) [1..temp] >>

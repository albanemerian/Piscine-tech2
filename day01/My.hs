{-
-- EPITECH PROJECT, 2025
-- B-PDG-300-NAN-3-1-PDGD01-albane.merian
-- File description:
-- My
-}

mySucc :: Int -> Int
mySucc n = n + 1

myIsNeg :: Int -> Bool
myIsNeg x = x < 0

myAbs :: Int -> Int
myAbs x
  | x < 0     = -x  
  | otherwise = x   

myMin :: Int -> Int -> Int
myMin x a
    | x < a = x
    | otherwise = a

myMax :: Int -> Int -> Int
myMax x a
    | x > a = x
    | otherwise = a

myTuple :: a -> b -> (a , b )
myTuple a b = (a , b )

myTruple :: a -> b -> c -> (a , b , c )
myTruple a b c = (a , b , c )

myFst :: (a , b ) -> a
myFst (a , b ) = a

mySnd :: (a , b ) -> b
mySnd (a , b ) = b

mySwap :: (a , b ) -> (b , a )
mySwap (a , b ) = (b , a )

myHead :: [a] -> a
myHead [] = error "Empty List"
myHead (x:_) = x 

myTail :: [ a ] -> [ a ]
myTail [] = error "Empty List"
myTail (_:x) = x

myLength :: [a] -> Int
myLength [] = 0
myLength (_:xs) = 1 + myLength xs


myNth :: [a] -> Int -> a
myNth [] _ = error "Index out of bounds"
myNth (x:_) 0 = x                
myNth (_:xs) n
  | n < 0     = error "Negative index is not allowed"
  | otherwise = myNth xs (n - 1)


myTake :: Int -> [a] -> [a]
myTake _ [] = []
myTake 0 _ = []
myTake n (x:xs) 
    | n <= 0 = []
    | otherwise = x : myTake (n - 1) xs


myDrop :: Int -> [a] -> [a]
myDrop _ [] = []
myDrop 0 xs = xs
myDrop n (x:xs)
    | n <= 0 = (x:xs)
    | otherwise = myDrop (n - 1) xs


myAppend :: [a] -> [a] -> [a]
myAppend [] ys = ys
myAppend (x:xs) ys = x : myAppend xs ys

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:xs) = myAppend (myReverse xs) [x] 

myInit :: [a] -> [a]
myInit [] = error "Empty List"
myInit xs = myReverse ( myDrop 1 (myReverse xs))

myLast :: [a] -> a
myLast [] = error "Empty List"
myLast [x] = x
myLast (_:xs) = myLast xs

myZip :: [a] -> [b] -> [(a,b)]
myZip [] _ = []
myZip _ [] = []
myZip (x:xs) (y:ys) = (x, y) : myZip xs ys

myUnzip :: [(a,b)] -> ([a] , [b])
myUnzip [] = ([], [])
myUnzip ((x, y):xs) = (x : xss, y : yss)
  where (xss, yss) = myUnzip xs


myMap :: (a -> b) -> [a] -> [b]
myMap _ [] = []
myMap f (x:xs) = f x : myMap f xs

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter f (x: xs)
  | f x = x : myFilter f xs
  | otherwise = myFilter f xs


myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl _ b [] = b
myFoldl f b (x:xs) =  myFoldl f (f b x) xs 


myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr _ b [] = b
myFoldr f b (x:xs) = f x (myFoldr f b xs)


myPartition :: (a -> Bool) -> [a] -> ([a] , [a])
myPartition _ [] = ([], [])
myPartition f (x:xs)
  | f x = (x : trues, falses)
  | otherwise = (trues, x : falses)
  where (trues, falses) = myPartition f xs

myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort _ [] = []
myQuickSort _ [x] = [x]
myQuickSort f (x:xs) = myAppend (myQuickSort f falss) (x : myQuickSort f trues)
  where (trues, falss) = myPartition (f x) xs

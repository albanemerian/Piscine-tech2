{-
-- EPITECH PROJECT, 2025
-- B-PDG-300-NAN-3-1-PDGD03-albane.merian
-- File description:
-- Tree
-}
module Tree where


data Tree a = Empty | Node (Tree a) a (Tree a)
    deriving (Show)

-- instance Show a => Show (Tree a) where
--     show Empty = "Empty"
--     show (Node left value right) = 
--         "Node (" ++ show left ++ ") " ++ show value ++ " (" ++ show right ++ ")"

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree value Empty = Node Empty value Empty
addInTree value (Node left nodeValue right)
    | value == nodeValue = Node left nodeValue right
    | value < nodeValue = Node (addInTree value left) nodeValue right
    | value > nodeValue = Node left nodeValue (addInTree value right)

instance Functor Tree where
    fmap _ Empty = Empty
    fmap f (Node left value right) = Node (fmap f left) (f value) (fmap f right)


myAp :: [a] -> [a] -> [a]
myAp [] ys = ys
myAp (x:xs) ys = x : myAp xs ys

listToTree :: Ord a => [a] -> Tree a
listToTree [] = Empty
listToTree (x:xs) = addInTree x (listToTree xs)

treeToList :: Ord a => Tree a -> [a]
treeToList Empty = []
treeToList (Node l val r) =  myAp (myAp (treeToList l) [val]) (treeToList r)

treeSort :: Ord a => [a] -> [a]
treeSort [] = []
treeSort a = treeToList (listToTree a)


myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr _ b [] = b
myFoldr f b (x:xs) = f x (myFoldr f b xs)

instance Foldable Tree where
    foldr f acc Empty = acc
    foldr f acc (Node l val r) = foldr f (f val (foldr f acc r)) l

-- printTree :: Show a => Tree a -> String
-- printTree tree = unlines (printTreeHelper tree 0)

-- printTreeHelper :: Show a => Tree a -> Int -> [String]
-- printTreeHelper Empty _ = ["Empty"]
-- printTreeHelper (Node left value right) level =
--     (replicate (level * 4) ' ' ++ show value) :
--     printTreeHelper left (level + 1) ++
--     printTreeHelper right (level + 1)


-- main :: IO ()
-- main = do
--     let myList = [5, 3, 8, 1, 4]
--     let tree = listToTree myList
--     let new_list = treeToList tree
--     -- putStrLn new_list
--     -- putStrLn $ printTree tree
--     print new_list


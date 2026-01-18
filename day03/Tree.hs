{-
-- EPITECH PROJECT, 2026
-- Pool-tek2
-- File description:
-- Day03
-}

data Tree a = Empty | Node (Tree a) a (Tree a)
    deriving (Show)

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree a Empty = (Node Empty a Empty)
addInTree a (Node x b y) = case a < b of
    True -> (Node (addInTree a x) b y)
    False -> (Node x b (addInTree a y))

instance Functor Tree where
    fmap f Empty = Empty
    fmap f (Node x a y) = Node (fmap f x) (f a) (fmap f y)

listToTree :: Ord a => [a] -> Tree a
listToTree [] = Empty
listToTree x = foldr addInTree Empty x

treeToList :: Tree a -> [a]
treeToList Empty = []
treeToList (Node x a y) = treeToList x ++ [a] ++ treeToList y

treeSort :: Ord a => [a] -> [a]
treeSort [] = []
treeSort x = treeToList (listToTree x)

instance Foldable Tree where
    foldMap f Empty = mempty
    foldMap f (Node l a r) =  (foldMap f l) <> (f a) <> (foldMap f r)

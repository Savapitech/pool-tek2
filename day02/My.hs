{-
-- EPITECH PROJECT, 2026
-- Pool-tek2
-- File description:
-- Day02
-}

mySucc :: Int -> Int 
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x
    | x < 0 = True 
    | otherwise = False

myAbs :: Int -> Int
myAbs x 
    | myIsNeg x = -x
    | otherwise = x

myMin :: Int -> Int -> Int
myMin x y
    | x < y = x
    | otherwise = y

myMax :: Int -> Int -> Int
myMax x y
    | x > y = x
    | otherwise = y

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead [] = error "The list is empty"
myHead (h:t) = h

myTail :: [a] -> [a]
myTail [] = error "The list is empty"
myTail (h:t) = t

myLength :: [a] -> Int
myLength [] = 0
myLength (_:t) = myLength t + 1

myNth :: [a] -> Int -> a
myNth [] y = error "The list is empty"
myNth (h:t) y
    | y > myLength (h:t) = error "Index out of range"
    | myIsNeg y = error "Negative index"
myNth (h:t) 0 = h
myNth (h:t) y = myNth t (y - 1)

myTake :: Int -> [a] -> [a]
myTake y [] = error "The list is empty"
myTake y (h:t)
    | y >= myLength (h:t) = h:t
    | myIsNeg y = error "N is negative"
myTake 0 (h:t) = []
myTake y (h:t) = h: myTake (y - 1) t

myDrop :: Int -> [a] -> [a]
myDrop y [] = error "The list is empty"
myDrop y (h:t)
    | myIsNeg y = error "N is negative"
    | y >= myLength (h:t) = []
myDrop 0 l = l
myDrop y (h:t) = myDrop (y - 1) t

myAppend :: [a] -> [a] -> [a]
myAppend [] x = x
myAppend (h:t) y = h : myAppend t y

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (h:t) = myAppend (myReverse t) [h]

myInit :: [a] -> [a]
myInit [] = error "The list is empty"
myInit x = myReverse (myDrop 1 (myReverse x))

myLast :: [a] -> a
myLast [] = error "The list is empty"
myLast x = myHead (myReverse x)

myZip :: [a] -> [b] -> [(a, b)]
myZip _ [] = []
myZip [] _ = []
myZip (h:t) (h2:t2) = (h, h2) : myZip t t2

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([],[])
myUnzip ((a,b) : y) = myTuple (a : myFst (myUnzip y)) (b : mySnd (myUnzip y))

myMap :: (a -> b) -> [a] -> [b]
myMap fn [] = []
myMap fn (x:xs) = fn x : myMap fn xs

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter fn [] = []
myFilter fn (x:xs)
    | fn x = x : myFilter fn xs
    | otherwise = myFilter fn xs

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl fn b [] = b
myFoldl fn b (x:xs) = myFoldl fn (fn b x) xs

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr fn b [] = b
myFoldr fn b x = myFoldr fn (fn (myLast x) b) (myTake (myLength x - 1) x)

myRevFilter :: (a -> Bool) -> [a] -> [a]
myRevFilter fn [] = []
myRevFilter fn (x:xs)
    | fn x = myRevFilter fn xs
    | otherwise = x : myRevFilter fn xs

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition _ [] = ([], [])
myPartition fn a = ((myFilter fn a), (myRevFilter fn a))

myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort _ [] = []
myQuickSort cmp (x:xs) =
    myAppend
        (myQuickSort cmp (myFilter (\y -> cmp y x) xs))
        (x : myQuickSort cmp (myRevFilter (\y -> cmp y x) xs))

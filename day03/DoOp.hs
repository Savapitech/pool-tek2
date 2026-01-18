{-
-- EPITECH PROJECT, 2026
-- Pool-tek2
-- File description:
-- Day03
-}

import Data.Maybe ()
import Data.Char (isDigit)
import System.Exit
import System.Environment

myElem :: Eq a => a -> [a] -> Bool
myElem a [] = False
myElem a (x:xs)
  | a == x = True
  | otherwise = myElem a xs

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv a b = Just (a `div` b)

safeMod :: Int -> Int -> Maybe Int
safeMod _ 0 = Nothing
safeMod a b = Just (a `mod` b)

myIsNeg :: Int -> Bool
myIsNeg x
    | x < 0 = True 
    | otherwise = False

myLength :: [a] -> Int
myLength [] = 0
myLength (_:t) = myLength t + 1

safeNth :: [a] -> Int -> Maybe a
safeNth [] y = Nothing
safeNth (h:t) y
    | y > myLength (h:t) = Nothing
    | myIsNeg y = Nothing
safeNth (h:t) 0 = Just h
safeNth (h:t) y = safeNth t (y - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just a) = Just (a + 1)

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup a [] = Nothing
myLookup a ((b,c) : xs)
    | a == b = Just c
    | otherwise = myLookup a xs

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo func Nothing _ = Nothing 
maybeDo func _ Nothing = Nothing
maybeDo func (Just x) (Just y) = Just (func x y)

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt ('-':xs)
    | all isDigit xs = Just (-(read xs :: Int))
    | otherwise = Nothing
readInt x
    | all isDigit x = Just (read x :: Int)
    | otherwise = Nothing

getLineLength :: IO Int
getLineLength = fmap length getLine

printAndGetLength :: String -> IO Int
printAndGetLength x = 
    putStrLn x >>
    return (myLength x)

printBox :: Int -> IO ()
printBox 1 = putStrLn "++"
printBox x = if x <= 0 
    then return ()
    else (putStrLn $ concat["+", replicate (x * 2 - 2) '-', "+"]) >>
        (putStr $ unlines $ replicate (x - 2) (concat["|",
            replicate(x * 2 - 2) ' ', "|"])) >>
        (putStrLn $ concat["+", replicate (x * 2 - 2) '-', "+"])  

concatLines :: Int -> IO String
concatLines n = if n > 0 then do 
    line <- getLine
    return line <> (concatLines(n - 1))
    else return ""

getInt :: IO (Maybe Int)
getInt = do
    line <- getLine
    return (readInt line)

myNth :: [a] -> Int -> a
myNth [] y = error "The list is empty"
myNth (h:t) y
    | y > myLength (h:t) = error "Index out of range"
    | myIsNeg y = error "Negative index"
myNth (h:t) 0 = h
myNth (h:t) y = myNth t (y - 1)


readIntU :: [Char] -> Int
readIntU [] = 0
readIntU ('-':xs)
    | all isDigit xs = (-(read xs :: Int))
    | otherwise = 0
readIntU x
    | all isDigit x = (read x :: Int)
    | otherwise = 0

safeDivE :: Int -> Int -> IO ()
safeDivE a b = case safeDiv a b of
    Nothing -> exitWith (ExitFailure 84)
    _ -> print $ a `div` b

safeModE :: Int -> Int -> IO ()
safeModE a b = case safeMod a b of
    Nothing -> exitWith (ExitFailure 84)
    _ -> print $ a `mod` b

cArgs :: String -> String -> IO ()
cArgs a b
    | readInt a == Nothing = exitWith (ExitFailure 84)
    | readInt b == Nothing = exitWith (ExitFailure 84)
    | otherwise = return ()

main :: IO ()
main = do
    a <- getArgs
    if (length a) < 3 then exitWith (ExitFailure 84) else cArgs (a!!0) (a!!2)
    case a !! 1 of
        "+" -> print $ readIntU (a !! 0) + readIntU (a !! 2)
        "-" -> print $ readIntU (a !! 0) - readIntU (a !! 2)
        "*" -> print $ readIntU (a !! 0) * readIntU (a !! 2)
        "/" -> safeDivE (readIntU (a !! 0)) (readIntU (a !! 2))
        "%" -> safeModE (readIntU (a !! 0)) (readIntU (a !! 2))
        _ -> exitWith (ExitFailure 84)

{-
-- EPITECH PROJECT, 2026
-- pushswap_checker.hs
-- File description:
-- Rush 2
-}

import System.Exit
import Data.Char (isDigit)
import System.Environment

mySa :: ([Int], [Int]) -> ([Int], [Int])
mySa (x, y) | length x < 2 = (x, y)
mySa ((x:xs), y) = (head xs : [x] ++ drop 1 xs, y)

mySb :: ([Int], [Int]) -> ([Int], [Int])
mySb (x, y) | length y < 2 = (x, y)
mySb (x, (y:ys)) = (x, head ys : [y] ++ drop 1 ys)

mySc :: ([Int], [Int]) -> ([Int], [Int])
mySc l = mySb (mySa l)

myPa :: ([Int], [Int]) -> ([Int], [Int])
myPa (x, []) = (x, [])
myPa (x, (y:ys)) = (y : x, ys)

myPb :: ([Int], [Int]) -> ([Int], [Int])
myPb ([], y) = ([], y)
myPb ((x:xs), y) = (xs, x : y)

myRa :: ([Int], [Int]) -> ([Int], [Int])
myRa (x, y) | length x < 2 = (x, y)
myRa ((x:xs), y) = (xs ++ [x], y)

myRb :: ([Int], [Int]) -> ([Int], [Int])
myRb (x, y) | length y < 2 = (x, y)
myRb (x, (y:ys)) = (x, ys ++ [y])

myRr :: ([Int], [Int]) -> ([Int], [Int])
myRr l = myRb (myRa l)

myRra :: ([Int], [Int]) -> ([Int], [Int])
myRra (x, y) | length x < 2 = (x, y)
myRra (x, y) = (last x : take (length x - 1) x, y)

myRrb :: ([Int], [Int]) -> ([Int], [Int])
myRrb (x, y) | length y < 2 = (x, y)
myRrb (x, y) = (x, last y : take (length y - 1) y)

myRrr :: ([Int], [Int]) -> ([Int], [Int])
myRrr l = myRrb (myRra l)

isSorted :: ([Int], [Int]) -> Bool
isSorted ([], []) = False
isSorted ([x], []) = True
isSorted ([_], [x]) = False
isSorted (x:xs, []) = x <= head xs && isSorted(xs, [])
isSorted (_, _) = False

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt ('-':xs)
  | all isDigit xs = Just(-(read xs))
  | otherwise = Nothing
readInt (x)
  | all isDigit x = Just(read x)
  | otherwise = Nothing

launchOp :: ([Int], [Int]) -> String -> ([Int], [Int])
launchOp x "sa" = mySa x
launchOp x "sb" = mySb x
launchOp x "sc" = mySc x
launchOp x "pa" = myPa x
launchOp x "pb" = myPb x
launchOp x "ra" = myRa x
launchOp x "rb" = myRb x
launchOp x "rr" = myRr x
launchOp x "rra" = myRra x
launchOp x "rrb" = myRrb x
launchOp x "rrr" = myRrr x
launchOp x _ = ([],[])

checkArgs :: [String] -> Int -> IO ()
checkArgs [] _ = exitWith (ExitFailure 84)
checkArgs _ (-1) = return()
checkArgs arg x
  | readInt (arg !! x) == Nothing = exitWith(ExitFailure 84) 
  | otherwise = checkArgs arg (x-1)

main :: IO()
main = do 
    args <- getArgs
    checkArgs args (length args - 1)
    ops <- fmap words getLine
    let (la, lb) = foldl launchOp (map read args, []) ops
    case isSorted (la, lb)  of
        True -> putStrLn("OK") >>
                return()
        False -> putStr("KO: ") >> print (la, lb) >>
          exitWith (ExitFailure 84)

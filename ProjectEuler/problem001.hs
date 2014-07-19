import Data.List (union)

answer = let n = 1000-1 in sum $ union [3,3*2 .. n] [5,5*2 .. n]
main = print answer

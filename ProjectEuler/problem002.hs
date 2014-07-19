fib :: [Integer]
fib = 1 : 2 : zipWith (+) fib (tail fib)
answer = (sum . filter even . takeWhile (< 4000000)) fib

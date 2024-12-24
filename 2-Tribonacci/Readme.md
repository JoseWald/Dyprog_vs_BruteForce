trib(n) = trib(n-1) + trib(n-2) + trib(n-3)
Every recurs call will be called 3 times

A brute force recursion will have O(3^n) time complexity which is pretty slow
The brute force recursion may be faster than the dynamic programming if trib(n)=> 0<= n <=15
But as long as the value of n increase , the time difference become larger

e.g on my computer:
-trib(12)
    Recursion + memo:
    =>274 done in : 27ms
    Brute Force:
    =>274 done in : 8ms

-trib(15)
    Recursion + memo:
    =>1705 done in : 16ms
    Brute Force:
    =>1705 done in : 20ms

-trib(40)
    Recursion + memo:
    =>7046319384 done in : 59ms
    Brute Force:
    =>7046319384 done in : 63949322ms
brute force recursion vs recursive code with memoization.

Brute force time complexity :O(2^n)
Recursive + memo time complexity :O(n)

e.g:
fib(40)
Recursion + memo:
 =>102334155 done in : 90ms
Brute Force:
 =>102334155 done in : 878739ms

Change the value of fib sequence you want to compute
Notice : You may not see the difference if you try fib(n) and n<=15
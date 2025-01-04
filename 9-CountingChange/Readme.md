In this problem , we gonna be given an amount and an array of coins value
What we gonna do is to return the number ways that possible to give the amount by the coins in the array
we can use a coin value as many times as we want

e.g: amount = 4 and coins =[ 1,2,3 ]
there's is 4 different ways to get the amount 
1+1+1+1
2+1+1
2+2
3+1
That's why we should return 4 as our output
N.B:-We can use the coin as many times we can but we should count the commutative sum just once
    -here , both 3+1 and 1+3 can give the amount but is should not be counted differently

   ----BENCHMARK----
-------------------
amount = 4
coins= {1,2,3}
Brute Force:
 =>4 done in : 19ms
Dyprog:
 =>4 done in : 28ms
-------------
amount = 5
coins= {2,4}
Brute Force:
 =>0 done in : 10ms
Dyprog:
 =>0 done in : 13ms
-------------------
amount = 50
coins= {1,2,3,4,5}
Brute Force:
 =>3765 done in : 10951ms
Dyprog:
 =>3765 done in : 706ms
---------------------

Brute force time complexity  = O(n^m)
Dyprog time complexity = O(n*m)
n=amount ; m= coin.size()
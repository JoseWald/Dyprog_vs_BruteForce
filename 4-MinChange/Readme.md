We gonna given an amount and an array of coins
We should return the minimum number of coin required to create the amount
For example
amount = 5 
coins = [ 1,2,3 ]
we can do 
1+1+1+1+1 or 1+2+2 or 1+1+3 or 2+3 but we should find the minimum number of coins to get the amount
so the best way to get the  given amount  is 2+3 so then , only 2 coins is resquired 

If there is no way to get the amount ,let's just return 0.

----BENCHMARK----
-------------------
amount =5 
coins = {1,2,3}
Brute Force:
 =>2 done in : 1ms
Dynamic Programming:
 =>2 done in : 6ms
--------------------
 amount = 25;
 coins = {1,2,3}
 Brute Force:
 =>9 done in : 2ms
Dynamic Programming:
 =>9 done in : 7ms
-------------------
amount = 250
coins = {7,9,2}
Brute Force:
 =>28 done in : 4ms
Dynamic Programming:
 =>28 done in : 10ms
---------------------
amount = 2500
coins = {8,5,6,1}
Brute Force:
 =>316 done in : 72ms
Dynamic Programming:
 =>316 done in : 29ms
---------------------
amount = 5000
coins = {5,7,6,4}
Brute Force:
 =>0 done in : 131ms
Dynamic Programming:
 =>0 done in : 38ms
---------------------
amount = 5000
coins = {5,7,6,4,1}
Brute Force:
 =>716 done in : 146ms
Dynamic Programming:
 =>716 done in : 45ms

 Brute force complexity : O(c^amount) , c = number of coin
 Dyprog complexity : O(c*amount)
We should review what a perfect square is : we can get a perfect square by taking a number and
multiplying it with itself.
e.g:1 , 4 , 9 , 16  that is 1*1 , 2*2 ,3*3 ,4*4

In this problem , we should output the number of perfect square that sum up the target number.
e.g : Input = 12
        -> 4+4+4=12
        ->9+1+1+1=12
        ->1+1+1+1+1+1+1+1+1+1+1+1=12
        ->and so on
    Output = 3 because the least number of perfect square that we can sum to get 12 is 4+4+4


   ----BENCHMARK----
-------------------
input = 2

Brute Force:
 =>2 done in : 11ms
Dyprog:
 =>2 done in : 9ms
--------------------
input = 12
Brute Force:
 =>3 done in : 27ms
Dyprog:
 =>3 done in : 28ms
-------------------
input = 23
Brute Force:
 =>4 done in : 316ms
Dyprog:
 =>4 done in : 31ms
---------------------

Brute force time complexity  = O(sqrt(n)^n)
Dyprog time complexity = O(n*sqrt(n))
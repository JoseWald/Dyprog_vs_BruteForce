In this problem , we gonna take an array conatining some numbers
What we gonna do is to return the maximum sum of non adjacent elements
That means that we should never take the number next to each other

e.g : array = [2 ,4 ,5 ,12 ,7]
    => 2 + 5 + 7 =14
    => 4 + 12 =16
In this case , we should return 16.

 Brute force time complexity : O(2^n)
 Dyprog time complexity : O(n)
 n :: length of the array

   ----BENCHMARK----
-------------------
array = {2 ,4 ,5 ,14 ,7,2 ,4 ,5 ,14 ,7}

Brute Force:
 =>36 done in : 8ms
Dyprog:
 =>36 done in : 16ms
--------------------
 array = {2 ,4 ,5 ,14 ,7,2 ,4 ,5 ,14 ,7,45,78,6,9,8,7};
Brute Force:
 =>130 done in : 54ms
Dyprog:
 =>130 done in : 21ms
-------------------
 array = {2 ,4 ,5 ,14 ,7,2 ,4 ,5 ,14 ,7,45,78,6,9,8,7,2 ,4 ,5 ,14,5 ,14 }
Brute Force:
 =>162 done in : 1909ms
Dyprog:
 =>162 done in : 39ms
---------------------
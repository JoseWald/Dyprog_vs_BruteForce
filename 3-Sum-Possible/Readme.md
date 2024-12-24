We have an array that contains n values , we should return true if at least there is 
one way to get a given amount by  adding up some number in the array.

e.g: amount = 5 , number =[ 1 , 2 , 3 ]
    True because there are many ways to get this amount like  1+1+1+1+1=5 , 3+2 = 5 , 2+2+1 = 5 , and so on
N.B: if the given amount is 0 , we return True because , we can get 0 by adding none of the value stored in the array


[n is the length of the array , a is the given amount]
Brute force time complexity :O(n^a)
Dynamic prog time complexity : O(n*a)

---BENCHMARK---
______________
amount = 4 ; number = {1,2,3}
BRUTE FORCE 
True 
-> done in :3 ms
DYNAMIC PROG 
True 
-> done in :3 ms

amount = 15 ; number = {5,7,3,1}
BRUTE FORCE 
True 
-> done in :9 ms
DYNAMIC PROG 
True 
-> done in :19 ms


amount = 100 ; number = {7,14}
BRUTE FORCE 
False 
-> done in :156 ms
DYNAMIC PROG 
False 
-> done in :28 ms

amount = 200 ; number = {7,14,36};
BRUTE FORCE 
True 
-> done in :23210 ms
DYNAMIC PROG 
True 
-> done in :193 ms
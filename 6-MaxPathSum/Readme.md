In this problem we gonna given a grid,we should travel from the top left corner to the bottom right corner
But in this case , the grid is contained , the waited output is the max sum of value on the path
e.g:grid = [
            [ 1, 3 , 12],
            [ 5, 6 , 2]
           ]
there's is 3 different ways to travel from the top left corner to the bottom right corner
    -right right down => 1 + 3 + 12 +2 = 18
    -down rigth right => 1 + 5 + 6 + 2 = 14 
    -rigth down rigth => 1 + 3 +6 + 2 = 12
 
As a result , we should return 18 


 Brute force complexity : O( 2^(row+scols) )
 Dyprog complexity : O( rows * cols )

  ----BENCHMARK----
-------------------
grid = {
          {1,1},
          {8,5}
        };

Brute Force:
 =>14 done in : 1ms
Dyprog:
 =>14 done in : 9ms
--------------------
grid = {
         {1,3,12},
         {5,1,1}
        };
Brute Force:
 =>17 done in : 2ms
Dyprog:
 =>17 done in : 14ms
-------------------
grid = {
            {1,3,12},
            {5,20,1},
            {3,6,8}
        };
Brute Force:
 =>40 done in : 2ms
Dyprog:
 =>40 done in : 19ms
---------------------
grid = {
        {1,3,12,5,20,1,3,6,8,3,12,5},
        {5,20,1,3,6,8,3,6,8,3,12,50},
        {3,6,8,3,12,5,5,20,1,3,6,8},
        {5,20,1,3,6,8,3,6,8,3,12,50},
        {3,6,8,3,12,5,5,20,1,3,6,8},
        {1,3,12,5,20,1,3,6,8,3,12,5},
        {5,20,1,3,6,8,3,6,8,3,12,50},
        {3,6,8,3,12,5,5,20,1,3,6,8},
        {5,20,1,3,6,8,3,6,8,3,12,50},
        {3,6,8,3,12,5,5,20,1,3,6,8}
};
Brute Force:
 =>324 done in : 19737ms
Dyprog:
 =>324 done in : 108ms
---------------------
grid = {
        {1,3,12,5,20,1,3,6,8,3,12,5},
        {5,20,1,3,6,8,3,6,8,3,12,50},
        {3,6,8,3,12,5,5,20,1,3,6,8},
        {5,20,1,3,6,8,3,6,8,3,12,50},
        {3,6,8,3,12,5,5,20,1,3,6,8},
        {1,3,12,5,20,1,3,6,8,3,12,5},
        {5,20,1,3,6,8,3,6,8,3,12,50},
        {3,6,8,3,12,5,5,20,1,3,6,8},
        {5,20,1,3,6,8,3,6,8,3,12,50},
        {3,6,8,3,12,5,5,20,1,3,6,8},
        {1,3,12,5,20,1,3,6,8,3,12,5},
        {5,20,1,3,6,8,3,6,8,3,12,50},
        {3,6,8,3,12,5,5,20,1,3,6,8},
        {5,20,1,3,6,8,3,6,8,3,12,50},
        {3,6,8,3,12,5,5,20,1,3,6,8},
};
Brute Force:
 =>445 done in : 575166ms
Dyprog:
 =>445 done in : 197ms
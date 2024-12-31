We gonna be given a grid ,we should travel from the top left corner to the bottom right corner
So we should output the the number possible of the travel through the grid.
e.g: the grid's size is 2*3 : there's is 3 different ways to travel from the top left corner to the bottom right corner
    -right right down
    -down rigth right
    -rigth down rigth 
As a result , we should return 3

In this problem , some cases gonna be  ocuupied by wall and we can't travel through them
e.g :  if there is a wall at the top  right corner, we can only go through
    -right down right
    - down right right
So then , we should return 3

Notice : we can only move to the right or down 

 Brute force complexity : O( 2^(row+scols) )
 Dyprog complexity : O( rows * cols )

 ----BENCHMARK----
-------------------
grid = {
            {0,0,0},
            {0,0,0}
        };
Brute Force:
 =>3 done in : 2ms
Dyprog:
 =>3 done in : 15ms
--------------------
grid = {
            {0,0,1},
            {0,0,0}
        };
Brute Force:
 =>2 done in : 1ms
Dyprog:
 =>2 done in : 10ms
-------------------
grid = {
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0},
        };
Brute Force:
 =>364 done in : 182ms
Dyprog:
 =>364 done in : 116ms
---------------------
grid = {
          {0,0,0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,1,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,1,0,0,0,0,0,0},
          {0,0,1,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0,0,0},
};
Brute Force:
 =>19048 done in : 1381063ms
Dyprog:
 =>19048 done in : 371ms
---------------------

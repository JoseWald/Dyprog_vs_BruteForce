#include<iostream>
#include<unordered_map>
#include<chrono>
#include<vector>
#include <algorithm>
#include <limits>
using namespace std;

int bf_max_path_sum(const vector<vector<short>>& grid , ushort row=0 , ushort col=0 ){
    if( row==grid.size() || col==grid[0].size() ){
        return  INT8_MIN;//just an approximation to -inf
    }

    if(row == grid.size() -1 && col == grid[0].size() -1){
        return grid[row][col];
    }
            
    return grid[row][col] + max(bf_max_path_sum(grid , row+1 , col) , bf_max_path_sum(grid , row , col+1));
}

struct Coord{
    int x , y ; 
    bool operator==(const Coord& other) const {
        return (x==other.x) && (y==other.y);
    }
};
struct HashCoord{
    size_t operator()(const Coord& c) const {
        auto hash1 = hash<int>{}(c.x);
        auto hash2 = hash<int>{}(c.y);
        return hash1 ^ (hash2 << 1);
    }
};

int dp_max_path_sum(const vector<vector<short>>& grid , unordered_map<Coord , int , HashCoord>& memo ,ushort row=0 , ushort col=0 ){
    if( row == grid.size() || col == grid[0].size() ){
        return INT16_MIN;
    }

    if(row == grid.size() -1 && col == grid[0].size() -1){
        return grid[row][col];
    }
    if( memo.find({row, col}) != memo.end()){
        return memo[{row, col}]; 
    }
    memo[{row, col}] =  grid[row][col] + max(dp_max_path_sum(grid ,memo , row+1 , col) , dp_max_path_sum(grid , memo , row , col+1));  
    return memo[{row, col}];

}
int main(){
    vector<vector<short>> grid = {
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
    //Brute force
    auto start  =  chrono::high_resolution_clock::now();

    const int bf_result = bf_max_path_sum(grid);

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Brute Force:\n =>" << bf_result <<  " done in : " << duration.count() <<"ms" <<endl;

    //Recursion + memo
    unordered_map<Coord , int , HashCoord> memo;
    start  = chrono::high_resolution_clock::now();

    const int  dp_result = dp_max_path_sum(grid,memo);

    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Dyprog:\n =>" << dp_result <<  " done in : " << duration.count() <<"ms" <<endl;
    return 0;
}
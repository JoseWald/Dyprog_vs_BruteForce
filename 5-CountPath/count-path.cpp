#include<iostream>
#include<unordered_map>
#include<chrono>
#include<vector>
#include <algorithm>
using namespace std;


ushort bf_count_path(const vector<vector<uint8_t>>& grid , ushort row_pos=0 , ushort col_pos=0){
    //check if we are out of bound
    if(row_pos == grid.size() || col_pos == grid[0].size()){
        return 0;
    }

    //check if the wall are occupied
    if(grid.at(row_pos).at(col_pos)==1){
        return 0;
    }


    if(row_pos == grid.size()-1 && col_pos == grid[0].size()-1){
        return 1;
    }
    
    return bf_count_path(grid , row_pos+1 , col_pos) + bf_count_path(grid , row_pos , col_pos+1);
}

struct Coord{
    int x, y;
    bool operator==(const Coord& other) const { 
        return  x ==other.x &&  y ==other.y;
    }
};
struct HashCoord{
    size_t operator()(const Coord& coord) const {
        auto hash1 = hash<int>{}(coord.x);
        auto hash2 = hash<int>{}(coord.y);
        return hash1 ^ (hash2<<1);
    };
};
ushort dp_count_path(const vector<vector<uint8_t>>& grid , unordered_map<Coord , ushort , HashCoord>& memo , ushort row_pos=0 , ushort col_pos=0  ){
    //check if we are out of bound
    if(row_pos == grid.size() || col_pos == grid[0].size()){
        return 0;
    }

    //check if the wall are occupied
    if(grid.at(row_pos).at(col_pos)==1){
        return 0;
    }


    if(row_pos == grid.size()-1 && col_pos == grid[0].size()-1){
        return 1;
    }
    if(memo.find({row_pos  , col_pos}) != memo.end()){
        return memo[{row_pos  , col_pos}];
    }
    ushort res =dp_count_path(grid ,memo ,row_pos+1 , col_pos) + dp_count_path(grid ,memo, row_pos , col_pos+1);
    memo[{row_pos , col_pos}] = res;
    return dp_count_path(grid , memo ,row_pos+1 , col_pos) + dp_count_path(grid , memo ,row_pos , col_pos+1);
}

int main(){
    // 1: occupied by wall , 0: not occupied by wall
    vector<vector<u_int8_t>> grid = {
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
    //Brute force
    auto start  =  chrono::high_resolution_clock::now();

    const ushort bf_result = bf_count_path(grid);

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Brute Force:\n =>" << bf_result <<  " done in : " << duration.count() <<"ms" <<endl;

   
    //Recursion + memo
    unordered_map<Coord , ushort , HashCoord> memo;
    start  = chrono::high_resolution_clock::now();

    const ushort  dp_result = dp_count_path(grid,memo);

    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Dyprog:\n =>" << dp_result <<  " done in : " << duration.count() <<"ms" <<endl;
    return 0;
}
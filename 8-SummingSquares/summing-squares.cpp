#include<iostream>
#include<unordered_map>
#include<chrono>
#include<cmath>
#include <algorithm>
#include <climits>
using namespace std;


int bf_summing_squares(ushort input , int n=0){
    if(input <0){
        return INT_MAX;
    }
    if(input == 0){
        return n;
    }
    int min_sqr = INT_MAX;
    for(ushort i = input ; i>0 ; i--){
        if(sqrt(i) == floor(sqrt(i))){
           min_sqr =min(min_sqr , bf_summing_squares(input-i , n+1));
        }
            
    }
    return min_sqr;
}

int dp_summing_squares(ushort input ,unordered_map<int , int >& memo, int n=0){
    if(input <0){
        return INT_MAX;
    }
    if(input == 0){
        return n;
    }
    if(memo.find(input) != memo.end()){
        return memo[input];
    }
    int min_sqr = INT_MAX;
    for(ushort i = input ; i>0 ; i--){
        if(sqrt(i) == floor(sqrt(i))){
           min_sqr =min(min_sqr , dp_summing_squares(input-i,memo , n+1));
        }
            
    }
    memo[input] = min_sqr;
    return min_sqr;
}

int main(){
    ushort input = 23;
     //Brute force
    auto start  =  chrono::high_resolution_clock::now();

    const int bf_result = bf_summing_squares(input);

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Brute Force:\n =>" << bf_result <<  " done in : " << duration.count() <<"ms" <<endl;

    
     //Recursion + memo
    unordered_map<int , int> memo;
    start  = chrono::high_resolution_clock::now();

    const int  dp_result = dp_summing_squares(input,memo);

    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Dyprog:\n =>" << dp_result <<  " done in : " << duration.count() <<"ms" <<endl;
    return 0;
    
}
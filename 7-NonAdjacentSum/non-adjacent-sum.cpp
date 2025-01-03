#include<iostream>
#include<unordered_map>
#include<chrono>
#include<vector>
#include <algorithm>
using namespace std;

int bf_non_adjacent_sum(const vector<int>& array , int n=0){
    if(n >= array.size()){
        return 0;
    }
   
    return max(
        array[n] + bf_non_adjacent_sum(array, n+2) ,
        bf_non_adjacent_sum(array, n+1)
    );
}

int dp_non_adjacent_sum(const vector<int>& array ,unordered_map<int , int >& memo ,int n=0){
    if(n >= array.size()){
        return 0;
    }

    if(memo.find(n) != memo.end()){
        return memo[n];
    }
    memo[n] =  max(
        array[n] + dp_non_adjacent_sum(array,memo, n+2) ,
        dp_non_adjacent_sum(array,memo, n+1)
    );

    return memo[n];
}
int main(){
    vector<int> array = {2 ,4 ,5 ,14 ,7,2 ,4 ,5 ,14 ,7,45,78,6,9,8,7,2 ,4 ,5 ,14,5 ,14 };
     //Brute force
    auto start  =  chrono::high_resolution_clock::now();

    const int bf_result = bf_non_adjacent_sum(array);

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Brute Force:\n =>" << bf_result <<  " done in : " << duration.count() <<"ms" <<endl;

     //Recursion + memo
    unordered_map<int , int> memo;
    start  = chrono::high_resolution_clock::now();

    const int  dp_result = dp_non_adjacent_sum(array,memo);

    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Dyprog:\n =>" << dp_result <<  " done in : " << duration.count() <<"ms" <<endl;
    return 0;
}
#include<iostream>
#include<unordered_map>
#include<chrono>
#include<vector>
#include <algorithm>
using namespace std;

int bf_counting_change(int amount , vector<int> coins , int coin_index=0){
    if(amount <0 ){
        return 0;
    }
    
    if(amount == 0){
        return 1;
    }
    if(coin_index >= coins.size())
        return 0;
    int ways = 0;
    int coin_value = coins.at(coin_index);
    for(int quantity=0 ; quantity*coin_value<=amount ; quantity++){
        int sub_amount = amount - (quantity*coin_value);
        ways+=bf_counting_change(sub_amount,coins,coin_index+1);
    }
  
    return ways;
}
struct Amount_CoinIndex{
    int x , y;
    bool operator== (const Amount_CoinIndex& other) const{
        return (x==other.x) && (y==other.y);
    }
};
struct Hash_Validation{
    size_t operator()(const Amount_CoinIndex& c) const {
        auto h1 = hash<int>{}(c.x);
        auto h2 = hash<int>{}(c.y);
        return h1 ^ (h2 << 1);
    }
};
int dp_counting_change(int amount , vector<int> coins, unordered_map<Amount_CoinIndex , int , Hash_Validation>& memo , int coin_index=0){
    if(amount <0 ){
        return 0;
    }
    
    if(amount == 0){
        return 1;
    }
    if(coin_index >= coins.size())
        return 0;
    if(memo.find({amount,coin_index})!=memo.end()){
        return memo[{amount,coin_index}];
    }
    int ways = 0;
    int coin_value = coins.at(coin_index);
    for(int quantity=0 ; quantity*coin_value<=amount ; quantity++){
        int sub_amount = amount - (quantity*coin_value);
        ways+=dp_counting_change(sub_amount,coins,memo,coin_index+1);
    }
    memo[{amount,coin_index}]=ways;
    return ways;
}
int main(){
    int  amount = 50;
    vector<int> coins= {1,2,3,4,5};
    unordered_map<Amount_CoinIndex , int , Hash_Validation> memo;
     //Brute force
    auto start  =  chrono::high_resolution_clock::now();

    const int bf_result = bf_counting_change(amount , coins  );

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Brute Force:\n =>" << bf_result <<  " done in : " << duration.count() <<"ms" <<endl;
    
    //Recursion + memo
    start  = chrono::high_resolution_clock::now();

    const int  dp_result = dp_counting_change(amount, coins , memo);

    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Dyprog:\n =>" << dp_result <<  " done in : " << duration.count() <<"ms" <<endl;
    return 0;
}
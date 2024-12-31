#include<iostream>
#include<unordered_map>
#include<chrono>
#include<vector>
#include <algorithm>
using namespace std;



u_short bf_min_change(short& amount ,const vector<u_short>& coins ,short coin_number=0){
    if(amount == 0)
        return coin_number;
    if(amount < 0)
        return 0;
   
    //clog << amount << "&" << coin_number <<" "; 
    for(u_short coin : coins){
        short sub_amount= amount-coin;

        if(sub_amount >=0){
            coin_number++;
            return bf_min_change(sub_amount , coins , coin_number);
        }
    }

    return 0;
}


u_short dp_min_change(short& amount ,const vector<u_short>& coins ,unordered_map<u_short, short>& memo,short coin_number=0){
    if(amount == 0)
        return coin_number;
    if(amount < 0)
        return 0;
   
    //clog << amount << "&" << coin_number <<" "; 
    if(memo.find(amount) != memo.end())
        return memo.at(amount);
        
    memo[amount] = coin_number;
    for(u_short coin : coins){
        short sub_amount= amount-coin;
        if(sub_amount >=0){
            coin_number++;       
            return bf_min_change(sub_amount , coins , coin_number);
        }
    }

    return 0;
}



int main(){
    short amount =250;
    vector<u_short> coins = {7,9,2};
    //sorting the coins in DESC order so the high valued coin is taken first to make sure that we minimize the change number
    sort(coins.begin(), coins.end() , greater<u_short>());
    unordered_map<u_short ,short> memo;


    auto start  =  chrono::high_resolution_clock::now();

    short br_result = bf_min_change(amount , coins );

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Brute Force:\n =>" << br_result <<  " done in : " << duration.count() <<"ms" <<endl;

    start  =  chrono::high_resolution_clock::now();


    short dp_result = dp_min_change(amount , coins ,memo );

    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Dynamic Programming:\n =>" << dp_result <<  " done in : " << duration.count() <<"ms" <<endl;

    return 0;
}
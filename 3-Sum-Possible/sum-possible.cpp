#include<iostream>
#include<unordered_map>
#include<chrono>
#include<vector>
#include <algorithm>
using namespace std;



bool sum_possible_bf(int& amount ,const vector<int>& number){
    if(amount==0)
        return true;
    if(amount<0)
        return false;

    for(size_t num : number){
        int sub_amount = amount - num;
        if(sum_possible_bf(sub_amount,number)){
            return true;
        }
    }
    return false;
   
}



bool sum_possible(int amount ,const vector<int>& number , unordered_map<int , bool>& memo){
    if(amount==0)
        return true;
    if(amount<0)
        return false;
   
    if(memo.find(amount) !=memo.end())
        return memo[amount];

    for(size_t num : number){
        size_t sub_amount = amount - num;
        if(sum_possible(sub_amount,number,memo)){
            memo[amount] = true;
            return true;
        }
    }
    memo[amount]=false;
    return false;
   
}



int main(){
    int amount =200;
    vector<int> number={7,14,36};
    unordered_map<int , bool > memo;

    
    cout << "BRUTE FORCE " << endl;
    auto start  = chrono::high_resolution_clock::now();

    sum_possible_bf(amount , number ) ? cout << "True \n" : cout << "False \n" ;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "-> done in :"  << duration.count() << " ms" << endl;

    cout << "DYNAMIC PROG " << endl;
    start  = chrono::high_resolution_clock::now();

    sum_possible(amount , number ,memo) ? cout << "True \n" : cout << "False \n" ;

    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "-> done in :"  << duration.count() << " ms" << endl;
    return 0;
}
#include <iostream>
#include <unordered_map>
#include <chrono>
using namespace std;

//brute force
size_t trib(size_t n){
    if(n <= 1)
        return 0;
    if(n==2)
        return 1;
    return trib(n-1) + trib(n-2) + trib(n-3);
}


//with memoization
size_t trib(size_t n ,unordered_map<size_t , size_t>& memo){
    if(n<=1)
        return 0;
    if(n==2)
        return 1;
    if(memo.find(n) != memo.end())//check if memo[n] is already computed to avoid every recalculation
        return memo.at(n);
    size_t result = trib(n-1 , memo) + trib(n-2 , memo) + trib(n-3,memo);
    memo[n] = result;
    return result;
}
int main(){
    cout << "Tribonacci" << endl;
    //Recursion + memo 
    auto start  = chrono::high_resolution_clock::now();

    unordered_map<size_t , size_t> memo;
    const size_t memo_result = trib(40,memo);

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Recursion + memo:\n =>" << memo_result <<  " done in : " << duration.count() <<"ms" <<endl;

    // Brute force
    start  = chrono::high_resolution_clock::now();

    const size_t br_result = trib(40);

    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Brute Force:\n =>" << br_result <<  " done in : " << duration.count() <<"ms" <<endl;

  
    return 0;
}


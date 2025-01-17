#include <iostream>
#include <unordered_map>
#include <chrono>
using namespace std;

//brute force
size_t fib(size_t n){
    if(n<=1)
        return n;
    return fib(n-1) + fib(n-2);
}

//with memoization
size_t fib(size_t n ,unordered_map<size_t , size_t>& memo){
    if(n<=1)
        return n;
    if(memo.find(n) != memo.end())//check if memo[n] is already computed to avoid every recalculation
        return memo.at(n);
    size_t result = fib(n-1 , memo) + fib(n-2 , memo);
    memo[n] = result;
    return result;
}

int main(){
    //Recursion + memo 
    auto start  = chrono::high_resolution_clock::now();

    unordered_map<size_t , size_t> memo;
    const size_t memo_result = fib(40 ,memo);

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Recursion + memo:\n =>" << memo_result <<  " done in : " << duration.count() <<"ms" <<endl;

    // Brute force
    start  = chrono::high_resolution_clock::now();

    const size_t br_result = fib(40);

    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Brute Force:\n =>" << br_result <<  " done in : " << duration.count() <<"ms" <<endl;

    /*
        Recursion + memo:
        =>102334155 done in : 90ms
        Brute Force:
        =>102334155 done in : 878739ms
    */
    return 0;
}

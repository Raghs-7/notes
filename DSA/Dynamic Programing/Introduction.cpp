#include<iostream>
#include<vector>
using namespace std;

// ----------------------------------------L1----------------------------------------------
// fibonacci

// can be done by recurssion but it's not optimized like for calculating f(5) it calculate f(4) seprately and f(3) seprately

// memoization
// vector<int> dp( n+1,-1)
int fibonaci(int n, vector<int> &dp){
    // time complexity --> O(n)
    // space complexity --> O(n)

    if (n<=1) return n;
    
    if (dp[n]!=-1) return dp[n];

    return dp[n] = fibonaci(n-1, dp) + fibonaci(n-2, dp);
}

// recurssion into tabulation (Bottom up) 
// bottom up --> base case to the required answer
// recurssion --> answer to base case and then come back
/*

dp[0] = 0
dp[1] = 1
for (int i=2; i<=n; i++){
    dp[i] = dp[i-1] + dp[i-2];
}

Time complexity --> O(n)
space compeixty --> O(n)

better solution because we are elemenating the recurssion stack space
*/

// optimal solution (space optimized)
/*
dp1 = 0;
dp2 = 1;
for (int i=0; i<n; i++){
    dp2 = dp1 + dp2;
    dp1 = dp2 - dp1;
}
return dp2;

Time complexity --> O(n)
space complexity --> O(1)
*/

// ----------------------------------------L1(stair case problem)----------------------------------------------

// distinct way you can reach the nth step
// recurssion
/*
void stairCase(int n, int ){
    int result = 0;
    if (n<=1) return n;

    if (n>1){
        result += stairCase(n-1);
    }
    if (n>=2){
        result += stairCase(n-2);
    }
    return result;
}
similar to fibonacci
*/

// ----------------------------------------L3(----------------------------------------------


int main(){
    return 0;
}
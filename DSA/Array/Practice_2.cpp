#include<iostream>
#include<vector>
using namespace std;

void SubArrayWithSumK(vector<int> arr, int k){
    // subarray also contains negatives
    // arr -- [1, 2, 3,,-3, 1, 1, 1, 4, 2, -3], k=3

    // brute force -- genereate all subarray 
    // time complexity --> O(n^2)
    // space complexity --> O(1)

    // optimal solution
    // time complexity --> O(n)
    // space complexity --> O(n)  (using unordered map)
    // approach is by prefix sum    
}

int ncr(int n, int r){

    // To calculate ncr value
    int min = n-r > r ? r : n-r;
    int result = 1;
    for (int i=1; i<=r; i++){
        result = result * (n-i);
        result = result/i;
    }

    // time complexity --> O(n)
    // space complexity --> O(1)
}

void PrintRowInPascalTriangle(){
    
}



int main(){

    return 0;
}
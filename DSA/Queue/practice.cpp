#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class NextGreaterElement {
private:
    stack<int> st;
public:
    vector<int> nextGreaterElement(vector<int>& nums) {
        // like nums1 = {12, 2, 5, 2, 4, 6}
        //     result = {-1, 5, 6, 4, 6, -1}
        
        // appraoch 
        // let say you are at 5 for knowing the next greater element of first you should be knowing what is 
        // on the right of the 5
        // so you should travers from back
        vector<int> result(nums.size(), 0);

        for (int idx=nums.size()-1; idx>=0; idx--){
            if (st.empty()){
                result[idx] = -1;
            }
            else{
                while (!st.empty() && nums[idx]>=st.top()){
                    st.pop();
                }
                if (st.empty()) result[idx] = -1;
                else {
                    result[idx] = st.top();
                }
                st.push(nums[idx]);
            }
        }
        return result;
    }
};


class NextSmallestElmen{
private:
    stack<int> st;
public:
    vector<int> nextSmallestElment(vector<int> &arr){
        
        vector<int> result(arr.size(), 0);
        for (int idx=0; idx<arr.size(); idx++){
            if (st.empty()){
                result[idx] = -1;
                st.push(arr[idx]);
            }
            else {
                while (!st.empty() && arr[idx]<=st.top()){
                    st.pop();
                }
                if (st.empty()) result[idx] = -1;
                else result[idx] = st.top();
                st.push(arr[idx]);
            }
        }
        return result;
    }
};

class RainWater {
public:
    int trap(vector<int>& height) {
        
    }
};



class Solution {
private:

    void NextSmallerRight(vector<int>& arr, vector<int>& smallerR ){
        stack<vector<int>> st;


        for (int i=arr.size()-1; i>=0; i--){
            if (st.empty()){
                st.push({arr[i], i});
                // smallerR[i] = arr.size();
            }
            else {
                while (!st.empty() && arr[i]<=st.top()[0]){
                    st.pop();
                }
                if (st.empty()){
                    st.push({arr[i], i});
                    // smallerR[i] = arr.size();
                }
                else {
                    smallerR[i] = st.top()[1];
                    st.push({arr[i], i});
                }
            }
        }

    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        
        vector<int> smallerL(arr.size(), -1);
        vector<int> smallerR(arr.size(), arr.size());

        NextSmallerRight(arr, smallerR);
        stack<vector<int>> st;

        const int MOD = 1e9 + 7;
        for (int i=0; i<arr.size(); i++){
            if (st.empty()){
                st.push({arr[i], i});
            }
            else {
                while (!st.empty() && arr[i]<=st.top()[0]){
                    st.pop();
                }
                if (st.empty()){
                    st.push({arr[i], i});
                }
                else {
                    smallerL[i] = st.top()[1];
                    st.push({arr[i], i});
                }
            }

            // int x = i-smallerL[i];
            // cout << (i-smallerL[i]) << " " << (smallerR[i]-i) << endl ;
            // result += (arr[i])*(i-smallerL[i])*(smallerR[i]-i);
        }
        // return result;

        long long result = 0;
        for (int i = 0; i < arr.size(); i++) {
            int left = i - smallerL[i];
            int right = smallerR[i] - i;
            long long contrib = 1LL * arr[i] * left * right;
            result = (result + contrib % MOD) % MOD;
        }


        return (int)result;
    }
};


int main(){
    return  0;
}
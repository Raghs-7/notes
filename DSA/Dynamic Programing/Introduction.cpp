#include<iostream>
#include<vector>
#include<queue>
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


// ------------------------- Longest Increasing Subsequence ------------------------------------------
int lengthOfLIS(vector<int>& nums) {
    // Optimal solution is using BS --> O(nlogn) and O(n) space
    // dp solution is using ---> O(n^2) and O(n) space


    // ----------Dp
    int n = nums.size();
    vector<int> dp(n, 1);

    // dp[i] --> including element i what is the maximimum you can find

    for (int i=1; i<n; i++){
        
        int best = 1;
        for (int j=i-1; j>=0; j--){
            if (nums[j] < nums[i]) {
                best = max(best, dp[j]);
            }
        }
    }

    int result = 1;
    for( int num: dp){
        result = max(result, num);
    }

    return result;

    // ----------- Binary Search approach
    // arr = [1, 7, 8, 4, 5, 6, -1, 9]
    // 1, 7, 8
    // 1, 4, 5, 6, 9
    // -1, 9
    
    // idea is why use extra space to store different array
    // first 1, 7, 8                       nown[j 4 comes  (replace 7 with 4)
    // 1, 4, 8                             now this tells longest sequence is length 3 and also stores 1, 4 (it doesn't mean 1, 4, 8 is subsequence)
    // 1, 4, 5, 6                          now -1 comes
    // -1, 4, 5, 6                         
    // -1. 4. 5. 6, 9                      answer is length of this ---> 5

    
    

}


void rottenOranges(vector<vector<int>>& grid){

}

bool DetectCycleInUnDirectedGraph(vector<vector<int>>& graph){

    // bfs 
    // idea --> if you are at a node and you find a node that is not the parent but still visited then there's a cycle

    vector<int> vis(graph.size(), 0);

    queue<pair<int, int>> q; // node, parent

    q.push({0, -1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        vis[node] = 1;

        for (int i=0; i<graph[node].size(); i++){
            if (!vis[graph[node][i]]){
                q.push({graph[node][i], node});
                vis[graph[node][i]] = 1;
            }
            else if (graph[node][i] != parent){
                return true;
            }
        }
    }
    

    // but since there can be multiple components so we gotta run a for loop 
    return false;
}

void NumberOfDistinctIsland(vector<vector<int>>& grid){
    
}

int main(){
    return 0;
}
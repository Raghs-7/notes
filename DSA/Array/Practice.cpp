#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

// input --> 1, 2, 3, 4, 5 and d = 3 
// output --> 4, 5, 1, 2, 3
void leftRotation_by_Dplace(int d, int arr[], int n){
    // 1, 2, 3, 4 | 5, 6, 7    {d==4}
    // 4, 3, 2, 1 | 7, 6, 5
    // 5, 6, 7, 4, 3, 2, 1  
    d = d % n;
    if (d==0) return;
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
    return ;

    // Time complexity --> O(n)
    // Space complexity --> O(1)
}

void Element_not_appeard_once(int arr[], int n){
    // this array will not contain one number from 1 to n
    // [1, 2, 4, 5]  n == 5 your output is 3
    // solution other than hashing 

    // 1) sum appraoch 
    // time complexity --> O(n)
    // space complexity --> O(1)

    // 2) xor approach 
    // key concept is that when you xor the same number it result in zero 
    // zero xor any number is that number 

    // approach is XOR1 = 1 ^ 2 ^ 3 ^ 4 ^ 5
    // XOR2 == 1 ^ 2 ^ 4 ^ 5
    // answer is = XOR1 ^ XOR2
    // But time complexity will be O(2N) how is this a better approach ?
    // we will do this in O(n)
    // we will do like this XOR1 ^ (idx + 1)        for example if n is 5 then idx goes to 0 to 3  but idx+1 goes to 1 to 4 
    // in the end we will do XOR1 ^ n
    //  now it's O(n)
    
    return ;
}


void Max_consecutive_one(int arr[], int n){
    // arr[] = {1, 1, 0, 1, 1, 1, 0, 0, 1, 1}
    // answer would be --> 3
    

    return ;
}

void find_no_appeared_once(int arr[], int n){
    // every number appeared twice  except for 1 number job is to find that number
    // optimal approach is that you should XOR the whole array and in the end XOR --> result
    // because same element XOR cancel out each other 

    // time complexity --> O(n)
    // space complexity --> O(1)

    return;
}

void longest_subarray_with_given_sum(int arr[], int sum, int n){



    // 1) assuming every number is postitive
    // apply the greddy approach with two pointers 


    // 2) no assumption this approach will work for positive and negative and zero also 
    // using hasing {every element contain the prefix sum, sum of all the element before that postion and including itself}
    //  [. . .  . a | . . . . . . .]  sum = k 
    //  -(x-k)-|--k--
    //            'till a  prefix sum is let say x 
    // we will try to find the sub array which contain k as sum and also have last element as a 
    // so we can say that if i find an element with prefix sum as x-k then there will be a sub array that contain a as last element and also have sum == k
    // make a map that is 
    // { presum --> idx }

    return;
}

void two_sum(){

    // you can do this using tree data structure or map data structure 
    // triverse the array , ele = arr[ idx ] and then ask if you have (target - ele) in array if yes then return yes if no then add this on the map / tree
    // time complexity --> O( nlogn )
    // space complexity --> O( n )
    
    // two pointers approach  { without storing }
    // first sort the array in O( nlogn )
    // then apply the greedy approach 

    // time complexity --> O( nlogn )
    // space complexity --> O( n )
    // but in this approach you are destorting the array 

    return; 
}

void Sortarray_one_two_zero(int arr[], int n){
    // this array will contain only 0, 1, 2 not anything else 

    // brute force solution 
    // time complexity --> O( 2*n )
    // space compelxity --> O( n )

    // optimal approach 
    // Dutch national flag algorithm
    // using three pointers 
    // [0 ... low - 1 ] --> 0
    // [low ... mid - 1] --> 1
    // [high .... n-1 ] --> 2
    // time complexity -> O( n )

    // [0 .... low-1 ]  [low .... mid-1]  [mid .... high-1] ( unsorted part )  [ high ..... n-1]
    int low = 0;
    int mid = 0;
    int high = n-1;
    // while (arr[high]==2){
    //     high--;
    // }
    while ( mid<=high ){
        if ( arr[mid] == 0 ){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if ( arr[mid] == 1){
            mid++;
        }
        else { // arr[mid] == 2
            swap(arr[high],arr[mid]);
            high--;
        }
    }
    // time compelxity --> O(n)
    // space complexity --> O(1)
    return ;
}

int majority_element(int arr[], int n ){
    // an element is a majourity element if it's appears in the array more than n/2 times 
     
    // by using BST tree / map we can do this in 
    // time complexity --> O( nlogn ) + O( n )
    // space complexity --> O( 2*n )
    
    // optimal approach is Moore's voting algorithm
    // intution is that if an element exists more than n/2 times then if we do something like cnt++ if it's that element and cnt-- if it's some other element
    // and if that element is our majourity element then count should be positive
    //  {7, 7, 5, 7, 1, | 5, 7, | 5, 5, 7, 7, | 5, 5, 5, 5}  
    
    int cnt = 0;
    int el;
    for (int i=0; i<n; i++){
        if (cnt==0){
            cnt = 1;
            el = arr[i];
        }
        else if (arr[i]==el){
            cnt++;
        }
        else {
            cnt--;
        }
    }

    // this step is done if it's stated that the array might not contain the majourity element
    // otherwise just return el;
    cnt = 0;
    for (int i=0; i<n; i++){
        if (arr[i]==el) cnt++;
    }
    if (cnt>n/2) return el;

    return -1; 
}


void max_subarray_sum(int arr[], int n){
    // given that sum of an empty sub array is zero 

    // brute force solution is that we try all subarray and then get the maximum 
    // time complexity --> O( n**2 )
    // space complexity --> O( all possible combination )

    // optimal approach is kadane's algorithm
    // [-2, -3, 4, -1, -2, +1, 5, -3]
    // intution here is that when you start you have sum == -2 but after -2 you have two choice either add -3 or start with -3
    // if you add -3 then i would be result of -5 but it would be better if you just start with -3 rather than add -3 and do the sum as -5
    // and if your sum is positive then i don't apply this because positive + positive willl increase your sum not decrease it 
    int max = INT_MIN;
    int sum = 0;
    int start = -1;
    int ans_end = -1;
    int ans_start;
    for (int i=0; i<n; i++){
        if (sum==0) start = i;
        sum += arr[i];
        if (sum>max){
            max = sum;
            ans_start = start;
            ans_end = i;
        }
        if (sum<0){
            sum = 0;
        }
    }


    // time complexity --> O(n)
    // space complexity --> O(1)

    return;
}

void rearrage_in_sign_order(int arr[], int n){
    // given that your array size (n) is always even which contain half positive element and half negative element 
    // input --> [3, 1, -2, -5, 2, -4]
    // output --> [3, -2, 1, -5, 2, -4] they are in their orriginal order but one positive then other one is negative one negative then other one is positive

    // brute force solution 
    // time complexity --> O(2*n)
    // space complexity --> O(2*n)
    // just make two array and collect the positive and negative one seprately and then in another interation just one by one add them to the original array

    // optimal approach is that two pointer appraoch with exptra space
    // make a new result array and just triverse the array and if it is positive then insert it in it's given idx and if it is negative then insert it at it's idx

    // time complexity --> O(n)
    // space complexity --> O(n)
    return ;
}

void rearrage_in_sign_order_II(int arr[], int n){
    // now positive != negative 
    // now this will be done by brute force approach 
    
    return ;
}


void buy_sell_stock(int arr[], int n){
    // main intution here is that if you sell a stock in ith day then you must buy it in min(0 ot i-1) day in order to make maximum profit 
    int mini = arr[0];
    int profit = 0;
    for (int i=1; i<n; i++){
        int cost = arr[i]-mini;
        profit = max(profit,cost);
        mini = min(mini, arr[i]);
    }

    return ;    
}

vector<int> next_permutation(vector<int> arr, int n){
    // input --> {1, 2, 3}
    // all permutations --> { 1, 2, 3 }, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1} their order are in the sorted order in the order in which you will find them in a dictionary 
    
    // brute solution 
    // you generate all the possible permutations and sort them and then do a linear search of the input permutation and then find the next permutation 
    // time complexity --> O( n * n!)       { very high } 


    // optimal approach {only for cpp}
    // {2, 1, 5, 4, 3, 0, 0}
    // do like this 
    // {2, 1, 5, 4, 3, | 0, 0} no rearangement of right two number is greater than already existing number
    // {2, 1, 5, 4, | 3, 0, 0} same for this 
    // {2, 1, 5, | 4, 3, 0, 0} same for this 
    // {2, 1, | 5, 4, 3, 0, 0} same for this
    // {2, | 1, 5, 4, 3, 0, 0} but in this here 1 is present but we can rearrange to find the some combination greater than this but we want to find the next so just replace it with the min number greater than 1
    // so 1 is our break point 

    // break point is where arr[i] < arr[i+1]
    // because if you notice previously all the element is maintaining the continuty which is 5 >= 4 >= 3 >= 0 >= 0 { arr[i] >= arr[i-1] }

    // 1) find the break point 
    // 2) find the least number greater then the break point number 
    // 3) now rest of the element should be in sorted order  but in increasing order 

    int idx = -1;
    for (int i= n-2; i>0; i-- ){
        if (arr[i]<arr[i+1]){
            idx = i;
            break;
        }
    }
    
    if (idx==-1){
        reverse(arr.begin(), arr.end());
        return arr;
    }

    // now find the smallest larger number from right array
    for (int i = n-1; i<idx; i--){
        if (arr[i]>arr[idx]){
            swap(arr[i],arr[idx]);
            break;
        }
    }

    // just reverse the right array
    reverse(arr.begin()+idx+1, arr.end());

    return arr;
}


vector<int> leader_array(vector<int> arr){
    // the element whose all element in the right is greater then itself is the learder
    // you have to return the array which contain all the learder 
    // input --> [10, 22, 12, 3, 0, 6]
    // output --> [22, 12, 6]
    int n = arr.size();
    if (n==1) return arr;
    int max = arr[n-1];
    vector<int> result;
    result.push_back(max);
    for (int i = n-2; i>0; i--){
        if (max > arr[i]){
            result.push_back(arr[i]);
            max = arr[i];
        }
    }

    // Time complexity --> O(n)
    // space complexity --> O(1) {extra space} 
    // total space complexity --> O(n)

    return result;
}

int length_longest_consecutive_array(vector<int> arr){
    // longest consecutive array 
    // input --> {102, 4, 100, 1, 101, 3, 2, 1, 1}
    // output --> 4 because longest consecutive array is {1, 2, 3, 4}

    // better solution is 
    // first sort the array 
    // int mini = INT_MIN
    // sort(v.begin(), v.end());
    // for (int i=0; i<v.size(); i++){
    //    if (arr[i]==mini){
    //         pass;
    //     }
    //    else if (arr[i]-mini==1) length++;
    //    else length = 1 && mini = arr[i];
    // }

    // optimal approach 

    return ;
}

vector<vector<int>> set_Matrix_zeros(vector<vector<int>> matrix){
    // what you have to do is that if a zero exists then put that entrire row and colm as zero 

    // better appraoch will be that first mark all the zeros and then make marked row or colmn as zero 
    // Time complexity --> O(2*n*m)
    // space complexity --> O(n+m)

    // optimal approach (you cannot decrease time complexity because n*m is the time complexity to triverse the matrix)
    // Time complexity --> O(2*n*m)
    // space complexity --> O(1)
    // intution is that we will treat the first row as our hasing row in which we are marking if this row has a zero or not 
    // and same for the first colm 
    // but catch is that you need to create an extra variable for the arr[0][0] because that is coliding for rows and colms 

    int n = matrix.size();
    int m = matrix[0].size();
    int col0 = 1;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (matrix[i][j]==0) {
                // mark the i-th row
                matrix[i][0] = 0;
                // mark the j-th col
                if (j != 0){
                    matrix[0][j] = 0;
                }
                else {
                    col0 = 0;
                }
            }
        }
    }

    for (int i=1; i<n; i++){
        for ( int j=1; j<m; j++){
            if (matrix[i][j]!=0){
                // check for colm and row
                if (matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if (matrix[0][0] == 0){
        for (int j=1; j< n; j++){
            matrix[0][j] = 0;
        }
    }

    if (col0 == 0){
        for (int i=0; i<m; i++){
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

vector<vector<int>> rotate_by_90_degree(vector<vector<int>> matrix){
    

}

void SpiralTriversal(vector<vector<int>> matrix){
    int right = matrix[0].size();
    int left = 0;
    int top = 0;
    int bottom = matrix.size();

    while (left<=right && top<=bottom){
        for (int i=left; i<right; i++){
            cout << matrix[top][i] << " ";
        }
        top++;
        for (int i=top; i<bottom; i++){
            cout << matrix[i][right] << " ";
        }
        right--;
        if (top <= bottom){
            for (int i=right; i>=left; i--){
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }
        if (left <= right){
            for (int i=bottom; i>=top; i--){
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
}

int main(){

    return 0;
}
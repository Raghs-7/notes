// heap --> Complete binary tree that comes with a heap order property

// CBT --> every level is completely filled except from the last level
// ans nodes always leans towards the left

// heap order property --> 1) Max heap and 2) Min heap

#include<iostream>
#include<queue>
using namespace std;

//  heap --> also known as priority queue 
priority_queue<int> pq; // max heap

priority_queue<int, vector<int>, greater<int>> minheap; // min heap

// implement heap in form of array
//        Max heap
//          60
//       50    40
//    30    20 
//  heap = [, 60, 50, 40, 30, 20]
//  Node --> ith index
//  Left child --> 2*i
//  right child --> 2*i+1
//  parent --> i/2


// Insertion
// first insert it at the most left end
// then take it to it's correct position
// for example --> insert(55) 
//                      60( idx = 1)
//          50 (idx = 2)            40 (idx = 3)  
//  30 (idx = 4)  20 (idx = 5)   55 (idx = 6) 
// 
//               60
//          50        55
//       30    20   40 
// 

class heap{
public:
    int arr[100];
    int size = 0;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size++;
        int idx = size;
        arr[idx] = val;
        int parent = arr[idx/2];
        while (parent<arr[idx] && idx > 1){
            swap(arr[idx/2],arr[idx]);
            idx = idx/2;
            parent = arr[idx/2];
        }
    }

    void print(){
        for (int i=0; i< size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    // void deletion(){
    //     if (size==0) return;
        
    //     arr[1] = arr[size];
    //     size--;

    //     int i = 1;
    //     while (i<size){
    //         int leftIndex = 2*i;
    //         int rightIndex = 2*i+1;

    //         if (leftIndex < size && arr[i] < arr[leftIndex]){
                
    //         }
    //     }
    // }
};

void ExplainHeapifyAlgorithm(){
    // in this algorithm we are changing an array( a normal tree) to heap 


    return;
}

void ExplainHeapSort(){


    return;
}

int main(){

    return 0;
}
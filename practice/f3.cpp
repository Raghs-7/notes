#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int ALPHABET_SIZE = 256;

// counting sort for a specific character position
void countingSort(vector<string> &arr, int index){
	int n = arr.size();
	vector<string> output;
	vector<int> count(ALPHABET_SIZE, 0);

	for (string &s: arr)
		count[index < s.size() ? s[index] : 0 ]++;

	for (int i = 1; i<ALPHABET_SIZE; i++)
		count[i] += count[i-1];

	for (int i = n-1; i>=0; i--){
		int charIdx = index < arr[i].size() ? arr[i][index] : 0 ;
		output[--count[charIdx]] = arr[i];
	}

	arr = output;
}

void radixSort(vector<string> &arr)

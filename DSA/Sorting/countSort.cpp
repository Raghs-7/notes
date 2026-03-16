#include <iostream>
#include <vector>
using namespace std;

int maximum(vector<int>& v) { // Pass by reference to avoid copying
    int maxi = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (maxi < v[i]) maxi = v[i];
    }
    return maxi;
}

void countingSort(vector<int>& v) { // Pass by reference to modify original vector
    vector<int> hash_table(maximum(v) + 1, 0);
    vector<int> output(v.size());

    // Step 1: Count occurrences
    for (int ele : v) {
        hash_table[ele]++;
    }

    // Step 2: Compute prefix sum
    for (int idx = 1; idx < hash_table.size(); idx++) {
        hash_table[idx] += hash_table[idx - 1];
    }

    // Step 3: Build output array (Stable sorting)
    for (int idx = v.size() - 1; idx >= 0; idx--) {
        output[--hash_table[v[idx]]] = v[idx];
    }

    // Step 4: Copy sorted values back to original array
    v = output;
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    countingSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}

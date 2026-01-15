#include <iostream>
#include <vector>
using namespace std;

int getMax(vector<int> v) {
    if (v.size() == 0) return -1;
    int result = v[0];
    for (int idx = 1; idx < v.size(); idx++) {
        if (result < v[idx]) result = v[idx];
    }
    return result;
}

vector<int> CountingSort(vector<int> &v, int place) {
    int hashTable[10] = {0};

    // Counting occurrences of digits at the current place value
    for (int idx = 0; idx < v.size(); idx++) {
        int digit = (v[idx] / place) % 10;
        hashTable[digit]++;
    }

    // Convert to cumulative count
    for (int idx = 1; idx < 10; idx++) {
        hashTable[idx] += hashTable[idx - 1];
    }

    // Place elements in sorted order based on current digit
    vector<int> result(v.size());
    for (int i = v.size() - 1; i >= 0; i--) {
        int digit = (v[i] / place) % 10;
        result[--hashTable[digit]] = v[i];
    }

    return result;
}

void RadixSort(vector<int> &v) {
    int maxVal = getMax(v);
    int place = 1;
    while (maxVal > 0) {
        v = CountingSort(v, place);
        place *= 10;
        maxVal /= 10;
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    RadixSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <cstdlib> // for rand()
using namespace std;

class UniversalHash {
    int a, b, p, m;
public:
    UniversalHash(int prime, int size) {
        p = prime; // Large prime number
        m = size;  // Hash table size
        a = 1 + rand() % (p - 1); // Random a in range [1, p-1]
        b = rand() % p; // Random b in range [0, p-1]
    }

    int hash(int x) {
        return ((a * x + b) % p) % m;
    }
};

int main() {
    int prime = 101; // A prime number
    int tableSize = 10;

    UniversalHash hashFunction(prime, tableSize);

    // Testing hash function
    vector<int> keys = {15, 27, 39, 49, 56};
    for (int key : keys) {
        cout << "Hash of " << key << " is: " << hashFunction.hash(key) << endl;
    }

    return 0;
}

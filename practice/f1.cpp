#include <iostream>
#include <list>
using namespace std;
class HashTable {
    private:
    static const int SIZE = 10;
    list<pair<int, string>> table[SIZE];
    int hashFunction(int key) {
        return key % SIZE;
    }
    public:
    void insert(int key, string value) {
        int index = hashFunction(key);
        table[index].push_back({key, value});
    }

    string search(int key) {
        int index = hashFunction(key);
        for (auto &p : table[index])
            if (p.first == key)
                return p.second;
        return "Not Found";
    }
    
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove_if([key](pair<int, string> p) { return p.first == key; });
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";
            for (auto &p : table[i])
                cout << "(" << p.first << ", " << p.second << ") ";
            cout << endl;
            }
        }
    };
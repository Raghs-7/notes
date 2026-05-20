#include <bits/stdc++.h>
using namespace std;

// Function to explain and demonstrate std::vector
void ExplainVector() {
    cout << "=== std::vector ===" << endl;
    cout << "A dynamic array that can resize itself automatically." << endl;
    cout << "Internal Working: Uses a contiguous block of memory (like array) that grows dynamically." << endl;
    cout << "                 When capacity is exceeded, allocates new larger array (usually double size)," << endl;
    cout << "                 copies elements, and deallocates old array." << endl;
    cout << "Access Time: O(1) - Direct indexing like arrays, no traversal needed." << endl;
    cout << "Time Complexity: O(1) for access, O(1) amortized for push_back." << endl;
    cout << "Use when: You need a resizable array with fast random access." << endl;
    cout << endl;

    // Creating a vector
    vector<int> v;

    // Adding elements
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // Accessing elements
    cout << "Vector elements: ";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Using iterator
    cout << "Using iterator: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Size and capacity
    cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << endl;

    // Inserting at specific position
    v.insert(v.begin() + 1, 15); // Insert 15 at index 1
    cout << "After insert: ";
    for (int num : v) cout << num << " ";
    cout << endl;

    // Removing elements
    v.pop_back(); // Remove last element
    cout << "After pop_back: ";
    for (int num : v) cout << num << " ";
    cout << endl;

    // Access helpers
    cout << "v.front(): " << v.front() << ", v.back(): " << v.back() << endl;
    cout << "v.at(1): " << v.at(1) << " (safe indexed access with bounds checking)" << endl;
    cout << "v.empty(): " << boolalpha << v.empty() << ", v.size(): " << v.size() << endl;

    // Capacity operations
    cout << "Before reserve(20), capacity=" << v.capacity() << endl;
    v.reserve(20); // Reserve storage for at least 20 elements
    cout << "After reserve(20), capacity=" << v.capacity() << endl;
    v.shrink_to_fit(); // Ask container to reduce capacity to size
    cout << "After shrink_to_fit, capacity=" << v.capacity() << ", size=" << v.size() << endl;

    // Clear
    v.clear(); // Remove all elements
    cout << "After clear, size=" << v.size() << ", empty=" << v.empty() << endl;

    cout << endl;
}

// Function to explain and demonstrate std::list
void ExplainList() {
    cout << "=== std::list ===" << endl;
    cout << "A doubly-linked list." << endl;
    cout << "Internal Working: Each element is a node with data and two pointers (prev/next)." << endl;
    cout << "                 Nodes are scattered in memory, connected via pointers." << endl;
    cout << "Access Time: O(n) - Must traverse from beginning or end to reach element at index i." << endl;
    cout << "Time Complexity: O(1) for insert/delete at ends, O(n) for access." << endl;
    cout << "Use when: Frequent insertions/deletions in middle, no random access needed." << endl;
    cout << endl;

    // Creating a list
    list<int> l;

    // Adding elements
    l.push_back(10);
    l.push_back(20);
    l.push_front(5); // Add to front

    // Accessing elements (using iterator)
    cout << "List elements: ";
    for (auto it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Inserting in middle
    auto it = l.begin();
    advance(it, 1); // Move to second element
    l.insert(it, 15);

    cout << "After insert in middle: ";
    for (int num : l) cout << num << " ";
    cout << endl;

    // Removing elements
    l.remove(15); // Remove all occurrences of 15
    cout << "After remove 15: ";
    for (int num : l) cout << num << " ";
    cout << endl;

    // More operations
    cout << "list.front(): " << l.front() << ", list.back(): " << l.back() << endl;
    l.pop_front(); // Remove first
    l.pop_back(); // Remove last
    cout << "After pop_front/pop_back: "; for (int num : l) cout << num << " "; cout << endl;

    l.push_back(40); l.push_back(10); l.push_back(30);
    l.sort(); // Sort in ascending order
    cout << "After sort: "; for (int num : l) cout << num << " "; cout << endl;
    l.reverse(); // Reverse order
    cout << "After reverse: "; for (int num : l) cout << num << " "; cout << endl;

    l.clear();
    cout << "After clear, empty=" << boolalpha << l.empty() << ", size=" << l.size() << endl;

    cout << endl;
}

// Function to explain and demonstrate std::deque
void ExplainDeque() {
    cout << "=== std::deque ===" << endl;
    cout << "Double-ended queue, allows efficient insertion/deletion at both ends." << endl;
    cout << "Internal Working: Uses multiple fixed-size arrays (blocks) arranged in a map." << endl;
    cout << "                 The map is an array of pointers to blocks, allowing dynamic growth" << endl;
    cout << "                 at both ends without reallocation of all elements." << endl;
    cout << "Access Time: O(1) - Random access via index calculation to find correct block and offset." << endl;
    cout << "Time Complexity: O(1) for operations at ends, O(1) for random access." << endl;
    cout << "Use when: Need queue operations from both ends." << endl;
    cout << endl;

    // Creating a deque
    deque<int> dq;

    // Adding elements
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);

    cout << "Deque elements: ";
    for (int num : dq) cout << num << " ";
    cout << endl;

    // Accessing elements
    cout << "Front: " << dq.front() << ", Back: " << dq.back() << endl;

    // Removing elements
    dq.pop_front();
    dq.pop_back();

    cout << "After pop front and back: ";
    for (int num : dq) cout << num << " ";
    cout << endl;

    // More operations
    dq.push_front(1);
    dq.push_back(50);
    cout << "dq.front()=" << dq.front() << ", dq.back()=" << dq.back() << ", dq.size()=" << dq.size() << endl;
    cout << "dq.at(1)=" << dq.at(1) << " (safe check)" << endl;

    dq.clear();
    cout << "After clear, empty=" << boolalpha << dq.empty() << ", size=" << dq.size() << endl;

    cout << endl;
}

// Function to explain and demonstrate std::stack
void ExplainStack() {
    cout << "=== std::stack ===" << endl;
    cout << "LIFO (Last In, First Out) data structure." << endl;
    cout << "Internal Working: Adapter class that uses another container (deque by default)" << endl;
    cout << "                 as underlying storage. Provides LIFO interface." << endl;
    cout << "Access Time: O(1) - Only top element is accessible, no indexing." << endl;
    cout << "Time Complexity: O(1) for all operations." << endl;
    cout << "Use when: Need LIFO behavior, like function call stack." << endl;
    cout << endl;

    // Creating a stack
    stack<int> s;

    // Pushing elements
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack size: " << s.size() << endl;
    cout << "Top element: " << s.top() << endl;

    // Popping elements
    s.pop();
    cout << "After pop, top: " << s.top() << endl;

    // Check if empty
    while (!s.empty()) {
        cout << "Popping: " << s.top() << endl;
        s.pop();
    }

    cout << "Final stack empty: " << boolalpha << s.empty() << ", size: " << s.size() << endl;
    cout << endl;
}

// Function to explain and demonstrate std::queue
void ExplainQueue() {
    cout << "=== std::queue ===" << endl;
    cout << "FIFO (First In, First Out) data structure." << endl;
    cout << "Internal Working: Adapter class using deque as underlying container by default." << endl;
    cout << "                 Provides FIFO interface with front/back access." << endl;
    cout << "Access Time: O(1) - Only front and back elements are directly accessible." << endl;
    cout << "Time Complexity: O(1) for all operations." << endl;
    cout << "Use when: Need FIFO behavior, like task scheduling." << endl;
    cout << endl;

    // Creating a queue
    queue<int> q;

    // Pushing elements
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue size: " << q.size() << endl;
    cout << "Front element: " << q.front() << ", Back: " << q.back() << endl;

    // Popping elements
    q.pop();
    cout << "After pop, front: " << q.front() << endl;

    // Queue status
    cout << "Queue empty: " << boolalpha << q.empty() << ", size: " << q.size() << endl;

    // Process all elements
    while (!q.empty()) {
        cout << "Processing: " << q.front() << endl;
        q.pop();
    }

    cout << "Final empty after draining: " << boolalpha << q.empty() << endl;
    cout << endl;
}

// Function to explain and demonstrate std::priority_queue
void ExplainPriorityQueue() {
    cout << "=== std::priority_queue ===" << endl;
    cout << "Max-heap by default, elements with highest priority first." << endl;
    cout << "Internal Working: Uses a heap data structure (binary heap by default)." << endl;
    cout << "                 Elements are arranged in a complete binary tree where parent" << endl;
    cout << "                 nodes have higher priority than children." << endl;
    cout << "Access Time: O(1) for top element, O(log n) for push/pop due to heap operations." << endl;
    cout << "Time Complexity: O(log n) for insert/delete, O(1) for top." << endl;
    cout << "Use when: Need to always access the maximum/minimum element." << endl;
    cout << endl;

    // Creating a max-heap priority queue
    priority_queue<int> pq;

    // Pushing elements
    pq.push(10);
    pq.push(30);
    pq.push(20);

    cout << "Top element: " << pq.top() << ", size=" << pq.size() << ", empty=" << boolalpha << pq.empty() << endl;

    // Popping elements
    pq.pop();
    cout << "After pop, top: " << pq.top() << ", size=" << pq.size() << "" << endl;

    // Min-heap
    priority_queue<int, vector<int>, greater<int>> min_pq;
    min_pq.push(10);
    min_pq.push(30);
    min_pq.push(20);

    cout << "Min-heap top: " << min_pq.top() << endl;

    cout << endl;
}

// Function to explain and demonstrate std::set
void ExplainSet() {
    cout << "=== std::set ===" << endl;
    cout << "Ordered container with unique elements." << endl;
    cout << "Internal Working: Implemented as a red-black tree (self-balancing BST)." << endl;
    cout << "                 Each node has color (red/black) to maintain balance." << endl;
    cout << "                 Ensures logarithmic height for efficient operations." << endl;
    cout << "Access Time: O(log n) - Tree traversal to find elements." << endl;
    cout << "Time Complexity: O(log n) for operations." << endl;
    cout << "Use when: Need ordered unique elements, fast lookup." << endl;
    cout << endl;

    // Creating a set
    set<int> s;

    // Inserting elements
    s.insert(10);
    s.insert(20);
    s.insert(10); // Duplicate, won't be inserted

    cout << "Set elements: ";
    for (int num : s) cout << num << " ";
    cout << endl;

    // Finding elements
    auto it = s.find(20);
    if (it != s.end()) {
        cout << "Found 20" << endl;
    }

    cout << "Count 20: " << s.count(20) << " (0 or 1 for set)" << endl;

    // Range queries
    auto lb = s.lower_bound(20);
    auto ub = s.upper_bound(20);
    if (lb != s.end()) cout << "lower_bound(20)=" << *lb << endl;
    if (ub != s.end()) cout << "upper_bound(20)=" << *ub << endl;
    auto erange = s.equal_range(20);
    cout << "equal_range size: " << distance(erange.first, erange.second) << endl;

    // Erasing elements
    s.erase(10);
    cout << "After erase 10: ";
    for (int num : s) cout << num << " ";
    cout << endl;

    s.clear();
    cout << "After clear, empty=" << boolalpha << s.empty() << ", size=" << s.size() << endl;

    cout << endl;
}

// Function to explain and demonstrate std::map
void ExplainMap() {
    cout << "=== std::map ===" << endl;
    cout << "Ordered associative container with key-value pairs." << endl;
    cout << "Internal Working: Same as set - red-black tree storing key-value pairs." << endl;
    cout << "                 Keys are ordered, values are associated with keys." << endl;
    cout << "                 Tree structure ensures balance and efficient search." << endl;
    cout << "Access Time: O(log n) - Tree traversal using key comparisons." << endl;
    cout << "Time Complexity: O(log n) for operations." << endl;
    cout << "Use when: Need key-value mapping with ordered keys." << endl;
    cout << endl;

    // Creating a map
    map<string, int> m;

    // Inserting elements
    m["Alice"] = 25;
    m["Bob"] = 30;
    m.insert({"Charlie", 35});

    cout << "Map elements:" << endl;
    for (auto& pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Accessing elements
    cout << "Alice's age: " << m["Alice"] << endl;

    // Finding elements
    auto it = m.find("Bob");
    if (it != m.end()) {
        cout << "Found Bob: " << it->second << endl;
    }

    cout << "Count Bob: " << m.count("Bob") << " (0 or 1 for map)" << endl;

    // Erasing elements
    m.erase("Alice");
    cout << "After erase Alice:" << endl;
    for (auto& pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }

    m.clear();
    cout << "After clear, empty=" << boolalpha << m.empty() << ", size=" << m.size() << endl;

    cout << endl;
}

// Function to explain and demonstrate std::unordered_set
void ExplainUnorderedSet() {
    cout << "=== std::unordered_set ===" << endl;
    cout << "Unordered container with unique elements, using hash table." << endl;
    cout << "Internal Working: Uses hash table with separate chaining or open addressing." << endl;
    cout << "                 Elements are distributed into buckets based on hash of key." << endl;
    cout << "                 Collisions handled by chaining (linked lists) or probing." << endl;
    cout << "Access Time: Average O(1), Worst case O(n) - Hash function + bucket access." << endl;
    cout << "Time Complexity: Average O(1) for operations." << endl;
    cout << "Use when: Need fast lookup, order doesn't matter." << endl;
    cout << endl;

    // Creating an unordered_set
    unordered_set<int> us;

    // Inserting elements
    us.insert(10);
    us.insert(20);
    us.insert(10); // Duplicate

    cout << "Unordered set elements: ";
    for (int num : us) cout << num << " ";
    cout << endl;

    // Finding elements
    if (us.find(20) != us.end()) {
        cout << "Found 20" << endl;
    }

    cout << "Count 20: " << us.count(20) << " (0 or 1)" << endl;
    cout << "Bucket count: " << us.bucket_count() << ", load factor: " << us.load_factor() << endl;
    us.rehash(20); // request at least 20 buckets
    cout << "After rehash(20), bucket_count: " << us.bucket_count() << endl;

    us.clear();
    cout << "After clear, empty=" << boolalpha << us.empty() << ", size=" << us.size() << endl;

    cout << endl;
}

// Function to explain and demonstrate std::unordered_map
void ExplainUnorderedMap() {
    cout << "=== std::unordered_map ===" << endl;
    cout << "Unordered associative container with key-value pairs, using hash table." << endl;
    cout << "Internal Working: Hash table storing key-value pairs in buckets." << endl;
    cout << "                 Keys are hashed to determine bucket, values stored with keys." << endl;
    cout << "                 No ordering guarantee, but very fast average-case access." << endl;
    cout << "Access Time: Average O(1), Worst case O(n) - Hash computation + bucket lookup." << endl;
    cout << "Time Complexity: Average O(1) for operations." << endl;
    cout << "Use when: Need fast key-value lookup, order doesn't matter." << endl;
    cout << endl;

    // Creating an unordered_map
    unordered_map<string, int> um;

    // Inserting elements
    um["Alice"] = 25;
    um["Bob"] = 30;

    cout << "Unordered map elements:" << endl;
    for (auto& pair : um) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Accessing elements
    cout << "Alice's age: " << um["Alice"] << endl;

    cout << "Count Bob: " << um.count("Bob") << " (0 or 1)" << endl;
    cout << "Load factor: " << um.load_factor() << ", max_load_factor: " << um.max_load_factor() << endl;
    um.reserve(10); // request internal bucket capacity for about 10 elements
    cout << "After reserve(10), bucket_count: " << um.bucket_count() << endl;

    um.erase("Alice");
    cout << "After erase Alice:, size=" << um.size() << endl;

    um.clear();
    cout << "After clear, empty=" << boolalpha << um.empty() << ", size=" << um.size() << endl;

    cout << endl;
}

int main() {
    cout << "C++ STL Introduction" << endl;
    cout << "===================" << endl;
    cout << endl;

    ExplainVector();
    ExplainList();
    ExplainDeque();
    ExplainStack();
    ExplainQueue();
    ExplainPriorityQueue();
    ExplainSet();
    ExplainMap();
    ExplainUnorderedSet();
    ExplainUnorderedMap();

    cout << "End of STL Introduction" << endl;
    return 0;
}
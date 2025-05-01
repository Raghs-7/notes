#include <iostream>
using namespace std;

// Node structure for AVL tree
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value) : key(value), left(nullptr), right(nullptr), height(1) {}
};

// Get height of a node (returns 0 for nullptr)
int getHeight(Node* node) {
    if (!node) return 0;
    return node->height;
}

// Get balance factor of a node
int getBalance(Node* node) {
    if (!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Update height of a node based on children's heights
void updateHeight(Node* node) {
    if (node) {
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    }
}

// Right rotation (fixes LL imbalance)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotation (fixes RR imbalance)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y;
}

// Insert a key into the AVL tree
Node* insert(Node* node, int key) {
    // Standard BST insert
    if (!node) return new Node(key);

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node; // Duplicate keys not allowed
    }

    // Update height of current node
    updateHeight(node);

    // Get balance factor
    int balance = getBalance(node);

    // Left-Left Case
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // Right-Right Case
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // Left-Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right-Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Inorder traversal to print the tree
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        std::cout << root->key << " ";
        inorder(root->right);
    }
}

// Free the tree memory
void freeTree(Node* node) {
    if (node) {
        freeTree(node->left);
        freeTree(node->right);
        delete node;
    }
}

int main() {
    Node* root = nullptr;

    // Insert some keys
    int keys[] = {10, 20, 30, 40, 50, 25};
    for (int key : keys) {
        root = insert(root, key);
    }

    // Print inorder traversal
    std::cout << "Inorder traversal of the AVL tree: ";
    inorder(root);
    std::cout << std::endl;

    // Clean up
    freeTree(root);
    return 0;
}
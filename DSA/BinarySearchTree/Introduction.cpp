#include<iostream>

//   [N]
// [L] [R]
// left is BST
// right is BST
// L < N < R   // ideally ther's no duplicate but we can make some edition to manage that also
// generally height is log2(n)

class ListNode{
public:
    int value;
    ListNode* next;
    ListNode(){
        value = 0;
        next = NULL;
    }
    ListNode(int a){
        int value = a;
        next = nullptr;
    }
};

class BinaryTree {
public: 
    int data;
    BinaryTree* right;
    BinaryTree* left;
    BinaryTree(){
        data = 0;
        right = nullptr;
        left = nullptr;
    }
    BinaryTree(int a){
        data = a;
        right = nullptr;
        left = nullptr;
    }
};

BinaryTree* Search(BinaryTree* head, int key){
    BinaryTree* result = new BinaryTree();
    result = head;
    while (result){
        if (result->data > key){
            result = result->left;
        }
        else if (result->data == key){
            return result;
        }
        else {
            result = result->right;
        }
    }
    return result;
}

BinaryTree* ceil(BinaryTree* head, int key){
    // figure out a lowest val that's >= key
    BinaryTree* temp = new BinaryTree();
    temp = head;
    BinaryTree* ans = new BinaryTree();
    ans = nullptr;
    while (temp){
        if (temp->data > key){
            ans = temp;
            temp->left;
        }
        else if (temp->data == key){
            return temp;
        }
        else {
            temp->right;
        }
    }
    return ans;
}

BinaryTree* Floor(BinaryTree* head, int key){
    // maximum value < = key
    BinaryTree* temp = new BinaryTree();
    temp = head;
    BinaryTree* ans = new BinaryTree();
    ans = nullptr;
    while (temp){
        if (temp->data > key){
            temp->left;
        }
        else if (temp->data == key){
            return temp;
        }
        else {
            ans = temp;
            temp->right;
        }
    }
    return ans;
}

BinaryTree* InsertNode(BinaryTree* head, int key){
    // there can be multiple possibility of inserting 
    BinaryTree* temp = new BinaryTree();
    temp = head;
    while (true){
        if (temp->data > key) {
            if (temp->left) temp->left;
            else {
                temp->left = new BinaryTree(key);
                return head;
            }
        }
        else if (temp->data == key) return head;
        else{
            if (temp->right) temp->right;
            else{
                temp->right = new BinaryTree(key);
                return head;
            }
        }
    }
}

BinaryTree* helper(BinaryTree* root1){
    if (root1->left==nullptr) return root1->right;
    else if (root1->right==nullptr) return root1->left;
    BinaryTree* rightChild = root1->right;
    BinaryTree* LastRight = root1->left;
    while (LastRight->right){
        LastRight = LastRight->right;
    }
    LastRight->right = rightChild;
    return root1->left;
}

BinaryTree* DeletionNode(BinaryTree* root, int key){
    // Time complexity --> O( height of the BST )
    // Space Complexity --> O( 1 )

    if (root == NULL) return NULL;
    if (root->data == key) return helper(root);
    BinaryTree* dummy = root;
    while (root){
        if (root->data > key){
            if (root->left != NULL && root->left->data == key){
                root->left = helper(root->left);
                break;
            }
            else {
                root = root->left;
            }
        }
        else {
            if (root->right != NULL && root->right->data == key){
                root->right = helper(root->right);
                break;
            }
            else  root = root->right;
        }
    }
    return dummy;
}

int main(){

    return 0;
}
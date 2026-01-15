#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int a){
        val = a;
        right = nullptr;
        left = nullptr;
    }
};

//  QUESTION 1

void InOrder_kth(TreeNode* root, int k, int result, int count) {
    if (!root || count >= k) return;

    InOrder_kth(root->left, k, result, count);
    count++;
    if (count == k) {
        result = root->val;
        return;
    }
    InOrder_kth(root->right, k, result, count);
}

// if you are said kth largest elemetn then do the inorder trivesal but maintain the order (right, root, left)
int kth_SmallestElement(TreeNode* root, int k) {
    int count = 0;
    int result = -1;
    InOrder_kth(root, k, result, count);
    return result;
}


// QUESTION 2
bool Valid_BST(TreeNode* root, int lowerBound, int UpperBound){ 
    // Intution in this code is that every no. should belong to a particular range 
    // Time complexity --> O(n)
    // Space complexity --> O(1)

    if (!root) return true;
    if (root->val <= lowerBound || root->val >= UpperBound) return false; 
    
    if (!Valid_BST(root->left, lowerBound, root->val)) return false;
    if (Valid_BST(root->right, root->val, UpperBound)) return false;
    
    return true;
}

// QUESTION 3
// LCA --> lowest common ancestors
TreeNode* LCA(TreeNode* root, int a, int b){
    // Intution is the moment they go in different direction that is their lca
    TreeNode* temp = root;
    while (temp){
        if (temp->val >= a && temp->val >= b) temp = temp->left;
        if (temp->val <=a && temp->val<=b) temp = temp->right;
        else return temp;
    }
    return nullptr;
}

// QUESTION 4
// call it like this
// int idx = 0;
// TreeNode* root = PreOrderToBST(preorder, INT_MAX, idx);
TreeNode* PreOrderToBST(const vector<int> &v, int UpperBound, int &curridx){ 
    if (UpperBound<v[curridx] || curridx >= v.size()) return nullptr;

    TreeNode* root = new TreeNode(v[curridx++]);
    root->left = PreOrderToBST(v, root->val, curridx);
    root->right = PreOrderToBST(v, UpperBound, curridx);
    return root;
}

// QUESTION 5
// InOrder Successor --> the smallest number that is greater than the given number is it's inorder successor
int InOrder_Successor(TreeNode* root, int key) {
    // Time Complexity --> O(Height of the Tree)
    // Space Complexity --> O(1)
    TreeNode* curr = root;
    TreeNode* successor = nullptr;
    while (curr) {
        if (key < curr->val) {
            successor = curr;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    return successor ? successor->val : -1;
}

// QUESTION 6
// InOrder Successor --> the largest number that is smaller than the given number 
int InOrder_Predessor(TreeNode* root, int key) {
    // Time Complexity --> O(Height of the Tree)
    // Space Complexity --> O(1)
    TreeNode* curr = root;
    TreeNode* Predessor = nullptr;
    while (curr) {
        if (key > curr->val) { 
            Predessor = curr;
            curr = curr->right;
        } else {  
            curr = curr->left;
        }
    }
    return Predessor ? Predessor->val : -1;
}


// QUESTION 6
// This should support functions like next and hasNext and remember initially our pointer is null
// you are not allowed to store in order traversal
void BST_Iterator(TreeNode* root){
    // just do the what recursion do first do the left left left and if right exist then go to right and store left left left 
    // to implement this we use stack
    class BST_Itr{
    public:
        TreeNode* root = root;
        stack<TreeNode*> st;

        BST_Itr(TreeNode* a){
            root = a;
            TreeNode* temp = a;
            while (temp){
                st.push(temp);
                temp = temp->left;
            }
            delete temp;
        }

        int next(){
            TreeNode* Newnode = st.top();
            st.pop();
            int result = Newnode->val;
            Newnode = Newnode->right;
            while (Newnode){
                st.push(Newnode);
                Newnode = Newnode->left;
            }
            return result;
        }

        bool hasnext(){
            return !st.empty();
        }
    };
    
    return;
}


int main(){

    return 0;
}
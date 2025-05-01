#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


class TreeNode{
public:
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode( int val){
        data = val;
        left = right = nullptr;
    }
    TreeNode(){
        data = 0;
        left = right = nullptr;
    }
};

// class ListNode {
// public:
//     int data;
//     ListNode* next;
//     ListNode(){
//         data = 0;
//         next = nullptr; 
//     }
//     ListNode(int a){
//         data = a;
//         next = nullptr;
//     }
// };

// class Queue{
// private:
//     ListNode* start;
//     ListNode* end;
//     int size;
// public:
//     Queue(){
//         start = nullptr;
//         end = nullptr;
//         size = 0;
//     }

//     bool IsEmpty(){
//         return (size==0);
//     }

//     void push(int x){
//         ListNode* newNode = new ListNode(x);
//         if (start==nullptr){
//             start = newNode;
//             end = newNode;
//         }
//         else {
//             end->next = newNode;
//             end = end->next;
//         }
//         size++;
//         return ;
//     }

//     int pop(){
//         if (start==nullptr){
//             cout << "Empty Queue" << endl;
//             return ;
//         }
//         int poped = start->data;
//         size--;
//         if (!size) end = nullptr;
//         return poped;
//     }

//     int seek(){
//         if (start==nullptr){
//             cout << "Empty Queue" << endl;
//             return -1;
//         }
//         return start->data;
//     }

//     int getSize(){
//         return size;
//     }
// };

void TypeofBinaryTree(){
    // if a tree is binary then it has only two childrens
    // 
    //    []  -- > this is root 
    //   /  \ 
    //  []  [] -- > this is children  --> leaf (if this node don't have children) 
    //  Ancestors --> all the parents you have and their parents all are this nodes ancestor's

    // Type of binary tree

    //  1) Full binary Tree -- > when every node has either 0/2 childrens
    //          []
    //      []      []
    //   []    []  

    //  2) complete Binary Tree -- > all leafs are completely filled except the last leaf && the last leaf has all nodes as left as possible 
    //              []
    //           []     []
    //         []  []
    //  ----------------------------
    //         []       |      []
    //     []       []  |   []      []
    //   []  []   []    | []   []   
    //  all three are complete Binary Tree

    // 3) Perfect Binary Tree -- > all leaf nodes are at same level

    // 4 ) Balanced Binary Tree -- > height of tree at non log(n), where n is no. of nodes

    // 5) Degenrate Binary Tree -- > when even every nodes have only one children

    return ;
}

void RepresentationOfBinaryTrees(){
    
    //      [5]
    //   [6]   [7]

    //       { , 5, }
    //        /    \
    //    { , 6, } { , 7, }
    // 

    struct Node{
        int data;
        struct Node* left;
        struct Node* right;
        Node( int val){
            data = val;
            left = right = NULL;
        };
    };

    // main function will look like this 
    // main() {
    // struct Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->right = new Node(5);
    // }

    return ;
}


void TranversalTechniques(){

    // 1) DFS --> depth wise    
    // Inorder Tranversal(left, root, right)     |  In means root is in 
    // Pre-order Tranversal(root, left, right)   |  Pre means root is pre 
    // Post-order Tranversal(left, right, root)  |  post means root is post 

    // 2) BFS --> breath wise 
}

void PreOrderTraversal( TreeNode* head){ // (root, left, right)
    if (head==NULL) return;
    cout << head->data << " ";

    PreOrderTraversal(head->left);
    PreOrderTraversal(head->right);
}

vector<int> PreOrderTravesalWithoutRecurrsion( TreeNode* head){ // (root, left, right)
    // we will use stack
    vector<int> ans;
    stack<TreeNode*> s;
    s.push(head);
    while (!s.empty()){
        TreeNode* temp = s.top();
        s.pop();
        if (temp->right) s.push(temp->right);
        if (temp->left) s.push(temp->left);
        ans.push_back(temp->data);
    }
    return ans;
    // Time Complexity = O(n)
    // Space Complexity = O(n) // zig zag tree
}

void InOrderTraversal( TreeNode* head) {
    if (head == NULL) return;

    InOrderTraversal(head->left);  // Traverse left subtree
    cout << head->data << " ";      // Visit root
    InOrderTraversal(head->right);  // Traverse right subtree
}

vector<int> InOrderTraversalWithoutRecurrsion( TreeNode* head){ // (left, root, right)
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* temp = head;
    while (true){
        if (temp){
            st.push(temp);
            temp = temp->left;
        }
        else {
            if (st.empty()) break;
            temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
}

void PostOrderTriversal( TreeNode* head){
    if (head == NULL) return;

    PostOrderTriversal(head->left);
    PostOrderTriversal(head->right);
    cout << head->data << " ";
}

vector<int> PostOrderTriversalWithoutRecurssion2( TreeNode* head){  // (left, right, root)
    // using two stacks
    vector<int> ans;
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    st1.push(head);
    while (st1.empty()){
        TreeNode* root = st1.top();
        st1.pop();
        st2.push(root);
        if (root->left) st1.push(root->left);
        if (root->right) st2.push(root->right);
    }
    while (!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    
    return ans;
}

vector<int> PostOrderTriversalWithoutRecurssion1(){
    // with one stack only 
    vector<int> ans;
    vector<TreeNode*> st;
    

}


vector<vector<int>> levelOrderTriversal( TreeNode* head){ // level order triversal
    // we will use Quese and Vector<vector<int>>
    TreeNode* temp = head;
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(temp);
    while (!q.empty()){
        int size = q.size();
        vector<int> level;
        for (int i=0; i<size; i++){
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
            level.push_back(tmp->data);
        }
        ans.push_back(level);
    }
    return ans;

    // Time Complexity = O(n)
    // Space Complexity = O(n)
}

vector<int> iterative_postorder_traversal(){ // interative and using one stack only 
    // left right root   
    // with recurssion it will do left left left then right right right then do the center 
    
    
}


int main(){

    return 0;
}
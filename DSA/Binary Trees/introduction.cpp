#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node( int val){
        data = val;
        left = right = NULL;
    };
};


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

void PreOrderTraversal(struct Node* head){ // (root, left, right)
    if (head==NULL) return;
    cout << head->data << " ";

    PreOrderTraversal(head->left);
    PreOrderTraversal(head->right);
}

void InOrderTraversal(struct Node* head) {
    if (head == NULL) return;

    InOrderTraversal(head->left);  // Traverse left subtree
    cout << head->data << " ";      // Visit root
    InOrderTraversal(head->right);  // Traverse right subtree
}


void PostOrderTriversal(struct Node* head){
    if (head == NULL) return;

    PostOrderTriversal(head->left);
    PostOrderTriversal(head->right);
    cout << head->data << " ";
}


void BreathWiseTriversal(){
    // we will use Quese and Vector<vector<int>>
}

int main(){

    return 0;
}
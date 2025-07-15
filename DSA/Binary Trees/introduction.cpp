#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<hash_map>
#include<unordered_map>
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
    TreeNode* curr = head;
    while (true){
        if (curr){
            st.push(curr);
            curr = curr->left;
        }
        else {
            if (st.empty()) break;
            curr = st.top();
            st.pop();
            ans.push_back(curr->data);
            curr = curr->right;
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

vector<int> PostOrderTriversalWithoutRecurssion1(TreeNode* root){
    // with one stack only 
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while (!curr || !st.empty()){
        if (curr!=nullptr){
            st.push(curr);
            curr = curr->left;
        }
        else {
            TreeNode* temp = st.top()->right;
            if (temp==nullptr){
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while (!st.empty() && temp==st.top()->right){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else {
                curr = temp;
            }
        }
    }
    return ans;
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

void heightOfBT_recurssion( TreeNode* head, int height, int& result){ // enter result as zero
    if (head==nullptr){
        if (result<height) result = height;
    }

    heightOfBT_recurssion(head->right, height+1, result);
    heightOfBT_recurssion(head->left, height+1, result);

}

// balanced BT is when height of right BT - height of Left BT <= 1
int balanced_BT(TreeNode* head, int &result){ // result = 1 (initially);
    if (head==nullptr){
        return 0;
    }
    int x = balanced_BT(head->right, result);
    int y = balanced_BT(head->left, result);
    if (!abs(x-y)<=1) result &= 0;
}

// diameter
// longest path between two nodes && path doesnot need to pass via root

// basic intution to solve this 
//             root
// left height      right height
int diameter_BT(TreeNode* root, int& diameter){

    if (root==nullptr){
        return 0;
    }

    int lh = diameter_BT(root->left, diameter);
    int rh = diameter_BT(root->right, diameter);
    diameter = max(lh+rh, diameter);
    
    return max(lh,rh)+1;
}

int Max_path_sum(TreeNode* root, int &max_sum){
    if (root == nullptr){
        return 0;
    }

    int ls = Max_path_sum(root->left, max_sum);
    int rs = Max_path_sum(root->right, max_sum);
    max_sum = max(max_sum, ls+rs+root->data);

    int result = max(ls, rs) + root->data;
    if (result) return 0;
    else return result;
}

class ZigZagLevelOrder {
private:
    queue<TreeNode*> q;
    void solve(TreeNode* root, vector<vector<int>> &result){
        TreeNode* temp = root;
        q.push(temp);
        int flag = 1;
        while (!q.empty()){
            int length = q.size();
            cout << length << endl;
            vector<int> level;
            for (int i=0; i<length; i++){
                TreeNode* t = q.front();
                q.pop();
                level.push_back(t->data);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            if (!flag) reverse(level.begin(), level.end());
            flag = !flag;
            result.push_back(level);
        }

    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return {};
        solve(root, result);
        return result;
    }
};

class VerticalTriversal {
private:
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {


    }
};

class RightView_BT{
private:
    // we are doing something like root, right , left    triversal
    void solve(TreeNode* root, int level, vector<int> &result){
        if (!root) return;

        if (level==result.size()) result.push_back(root->data); // first time on that level

        solve(root->right, level+1, result);
        solve(root->left, level+1, result);
    }
public:
    vector<int> RightView(TreeNode* root){
        vector<int> result;
        solve(root, 0, result);
        return result;
    }
};


class Symetric_BT{
private:
    bool solve(TreeNode* l_tree, TreeNode* r_tree){
        if (l_tree->data!=r_tree->data) return false;


        return (solve(l_tree->right, r_tree->left)&solve(l_tree->left, r_tree->right));
        
    }
public:
    bool IsSymetric(TreeNode* root){
        return solve(root->right, root->left);
    }
};

class LCA {
    TreeNode* solve(TreeNode* root,TreeNode* p, TreeNode* q){
    
        if (root==nullptr || root==p || root==q){
            return root;
        }

        TreeNode* r_tree = solve(root->right, p, q);
        TreeNode* l_tree = solve(root->left, p, q);

        if (r_tree==nullptr){
            return l_tree;
        }
        else if (l_tree==nullptr){
            return r_tree;
        }
        else {
            return root;
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = solve(root, p, q);
        return ans;
    }
};

/*

     (0-base)           (1-base) 
        i                  i
2*i+1       2*i+2     2*i     2*i+1

*/
class WidthOFBT {
private:
    int solve(TreeNode* root){
        if (root==nullptr) return 0;
        
        queue<pair<TreeNode*, unsigned long long>> q;

        int result = 0;
        q.push({root, 0});
        unsigned long long start, last;

        while (!q.empty()){
            int s = q.size();
            start = q.front().second;
            for (int idx=0; idx<s; idx++){

                auto it = q.front();
                TreeNode* temp = it.first;
                unsigned long long i = it.second-start;
                q.pop();

                last = i;

                if (temp->left) q.push({temp->left, 2*i+1});

                if (temp->right) q.push({temp->right, 2*i+2});
            
            }
            int width = last+1;
            // cout << start << endl;
            // cout << last << endl;
            // cout << width << endl;
            if (width>result) result = width;

        }
        return result;
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        return solve(root);
    }
};


class ChildSum{
public:
    void solve(TreeNode* root){
        // post order triversal
        if (root==nullptr) return ;
        int child = 0;
        if (root->left){
            child += root->left->data;
        }
        else if (root->right){
            child += root->right->data;
        }

        if (child < root->data) {
            if (root->left) root->left->data = root->data;
            if (root->right) root->right->data = root->data;
        }
        else {
            root->data = child;
        }
        
        solve(root->left);
        solve(root->right);
        int tot = 0;
        if (root->left) tot += root->left->data;
        if (root->right) tot += root->right->data;
        if (root->left or root->right) root->data = tot; // In case of leaf node you won't update it 
    }
private:
    TreeNode* childSum(TreeNode* root){
        return root;
    }
};


class Distance_k{
private:
    void MarkParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left){
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right){
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
public:
    vector<int> distancek(TreeNode* root, TreeNode* target, int k){
        unordered_map<TreeNode*, TreeNode*> parent_track;
        MarkParent(root, parent_track);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        while (!q.empty()){
            int s = q.size();
            if (curr_level = k) break;
            curr_level++;
            for (int i=0; i<s; i++){
                TreeNode* curr = q.front(); q.pop();
                if (curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if (curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if (parent_track[curr] && !visited[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]] = true;
                }
            }
        }
        vector<int> result;
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            result.push_back(curr->data);
        }
        
        return result;
    }
};

class Morris_Traversal{
private:
public:
    void MorrisTriversal(TreeNode* root){

    }
};

int main(){

    return 0;
}
#include<iostream>
#include<vector>
// #include<pairs>
#include<queue>
using namespace std;

// graph is --> node and edges 

// Directed Graph --> is a graph where all the edges are directed
// undirected graph --> graph which is not directed graph 
// cycle in a graph --> start at a node and end at that node and if there's a single cycle in a graph then it's a cyclic graph 
// acyclic graph --> which are not cyclic graph 

// path --> can contain a lot of vertecies and nodes and each of them are reachable
// a node cannot appear twise in a path 

// Degree of a graph --> for an undirected graph is the number of edges that are attached to it is know as it's degree
// total degree of graph == 2 * (no. of edges)   { stands for undirected graph }
// for Directed graph 
// Outdegree --> number of outgoing edges called outdegree
// Indegree --> number of incomming edges are callled indegree

// edge weight --> they will assign it but if they don't assign in the question then we will assume one 

void RepresentationOfGraph(int n, int m){
    // given an undirected/directed  graphs which contain n nodes and m edges {let's assume undirected} 
    // In next line they will be giving you m lines that represent edges {given n = 5, m = 6}
    //  [2, 1]
    //  [1, 3]
    //  [2, 4]
    //  [3, 4]
    //  [2, 5]
    //  [4, 5]

    // wany of storing 
    // 1) Adjacecy matrix
    int matrix[n+1][n+1];
    // so basically if there's and edges then you make that 1 like if there's an edge between 1 and 3 so you go to matrix[1][3] and matrix[3][1] and mark both of them as 1
    // all the remaning guys are filled with zero's 
    // space --> n**2 { costly }
    for (int i=0; i< m; i++){
        int u, v;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
     }


    //  2) Adjacency List
    vector<int> adj[n+1];
    // now each index will be containing the list of number's from which it is connected 
    for (int i=0; i<m; i++){
        int u, v;
        // if it is an directed graph then it states u --> v
        adj[u].push_back(v);
        adj[v].push_back(u); // if it is an directed graph then this line will not be required 
    }
    // Space complexity --> O(2*E)  { E --> no. of edges }

    // How do you store a Weighted graph in weighted graph there is a weight corresponding to every edge

    // 1) In Adjacency list we will be just do one thing -->  matrix[u][v] = weight, matrix[v][u] = weight

    // 2) In Adjacency List we can store the elements in pairs --> adj[u].push_back(pair(v, weight)), and also change the list initialization vector<pair<int>> adj[n+1]
    
    return;
}

void traiversal(){

    //  1----2        5       8     10
    //  |    |      /   \     |
    //  3----4     6-----7    9
    // these are not four graphs theres a 4 components of a single graph 

    //  In traiversal you will never be able to reach to different component if you stats from one component
    //  this is why any triversal you do you will use something as visited array 

    return;
}

vector<int> explainBFS(int n, vector<int> adj[]){ // n--> no. of nodes 
    // Breath first search  also call as level wise triversal 
    //       1
    //    2     6     
    //  3  4  7  8
    //      5
    // let say for BFS our initial node is 6 then our bfs trivesal is 6 | 1 7 8 | 2 5 | 3 4
    
    //          1
    //     2        6
    //  3    4    7   9 
    //     5        8
    // above graph is stored like
    // 0 --> {}
    // 1 --> {2, 6}
    // 2 --> {1, 3. 4}
    // 3 --> {2, 5}
    // 4 --> {2, 5}
    // 5 --> {3, 4}
    // 6 --> {7, 9}
    // 7 --> {6, 8}
    // 8 --> {7, 9}
    // 9 --> {6, 8}

    // initially --> queue == {1 } {initial node}
    // visited --> arr = [0, 1, 0, 0, 0, 0, 0, 0, 0, 0]  {maked the starting node as 1}
    // next step --> keep taking out untill queue is not empty and print it out 
    // then add the non visited neighbour on queue

    queue<int> q;
    int vis[n] = {0};
    vis[0] = 1;
    q.push(0); // push the first element which is zero
    vector<int> bfs;
    while (!q.empty()){
        int node = q.front();
        bfs.push_back(node);
        q.pop();

        for (int i=0; i<adj[node].size(); i++){
            if (!vis[adj[node][i]]){
                vis[adj[node][i]] = 1;
                q.push(adj[node][i]);
            }
        }
    }
    // Space complexity --> O(3*n)
    // Time complexity --> O(n) + O(2E)
    return bfs;
}

void explainDFS(){



    return ;
}


int main(){

    return 0;
}
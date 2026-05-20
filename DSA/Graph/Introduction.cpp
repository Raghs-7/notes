#include<bits/stdc++.h>
#include<iostream>
#include<vector>
// #include<pairs>
#include<queue>
#include<set>
using namespace std;

// graph is --> node and edges 

// Directed Graph --> is a graph where all the edges are directed
// undirected graph --> graph which is not directed graph 
// cycle in a graph --> start at a node and end at that node and if there's a single cycle in a graph then it's a cyclic graph 
// acyclic graph --> which are not cyclic graph 

// path --> can contain a lot of vertecies and nodes and each of them are reachable
// a node cannot appear twise in a path 

// Degrees in a graph --> for an undirected graph is the number of edges that are attached to it is know as it's degree
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
    // let say for BFS our starting node is 6 then our bfs trivesal is 6 | 1 7 8 | 2 5 | 3 4
    
    //          1
    //     2        6
    //  3    4    7   9 
    //     5        8
    // above graph is stored like
    // adjacency list
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

void dfs(int node, vector<int> adj[], int vis[], vector<int> &result){
    vis[node] = 1;
    result.push_back(node);
    for (int i=0; i<adj[node].size(); i++){
        if (!vis[adj[node][i]]){
            dfs(adj[node][i], adj, vis, result);
        }
    }
}

void explainDFS(int n, vector<int> adj[]){
    // depth first search 
    //          1
    //      2       3    4
    //   5     6    7    8
    // dfs --> 1 2 5 6 3 7 4 8
    int vis[n] = {0};
    int start = 0;
    vector<int> result;
    dfs(start, adj, vis, result);
    // Space complexity --> O(3*n)
    // Time complexity --> O(n) + O(2E)

    return ;
}

int numberOfProvices(int n, vector<int> adj[]){

    vector<int> vis(n, 0);
    int result = 0;

    for (int i=0; i<n; i++){
        if (vis[i]==0){
            // dfs(i, adj, vis);
            result++;
        }
    }

    return result;
    
}



int NumberOfConnnectedComponents(vector<vector<int>> &grid){
    // matrix contain 0 and 1 only and 0 means water and 1 means land and all 8 type of connectivity is allowed 
    // now tell us how many islands ...

    int n = grid.size();
    int m = grid[0].size();

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            
        }
    }
}

// ==================== CYCLE DETECTION CLASS ====================

// intution for undirected graph is --> if you find a node neighbor already visited and not the parent then it's a cycle
// for directed graph --> 
class CycleDetection {
private:
    int numNodes;
    vector<int>* adjList;
    
    // Helper function for undirected graph DFS
    bool detectCycleDFSUndirected(int node, int parent, vector<int>& vis){
        vis[node] = 1;
        
        for (int i = 0; i < adjList[node].size(); i++){
            int neighbor = adjList[node][i];
            
            if (!vis[neighbor]){
                if (detectCycleDFSUndirected(neighbor, node, vis)){
                    return true;
                }
            }
            else if (neighbor != parent){
                return true;
            }
        }
        
        return false;
    }
    
    // Helper function for directed graph DFS using color marking
    // WHITE = 0 (not visited), GRAY = 1 (being processed), BLACK = 2 (completed)
    bool detectCycleDFSDirected(int node, vector<int>& color){
        color[node] = 1;  // Mark as GRAY (currently being processed)
        
        for (int i = 0; i < adjList[node].size(); i++){
            int neighbor = adjList[node][i];
            
            if (color[neighbor] == 0){
                // WHITE node: not yet visited
                if (detectCycleDFSDirected(neighbor, color)){
                    return true;
                }
            }
            else if (color[neighbor] == 1){
                // GRAY node: back edge found, cycle detected
                return true;
            }
        }
        
        color[node] = 2;  // Mark as BLACK (processing complete)
        return false;
    }

public:
    // Constructor
    CycleDetection(int n, vector<int>* adj) : numNodes(n), adjList(adj) {}
    
    // ============= UNDIRECTED GRAPH CYCLE DETECTION =============
    
    // DFS approach for undirected graph
    bool hasCycleUndirectedDFS(){
        vector<int> vis(numNodes, 0);
        
        for (int i = 0; i < numNodes; i++){
            if (!vis[i]){
                if (detectCycleDFSUndirected(i, -1, vis)){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    // BFS approach for undirected graph
    bool hasCycleUndirectedBFS(){
        vector<int> vis(numNodes, 0);
        vector<int> parent(numNodes, -1);
        
        for (int i = 0; i < numNodes; i++){
            if (!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                
                while (!q.empty()){
                    int node = q.front();
                    q.pop();
                    
                    for (int j = 0; j < adjList[node].size(); j++){
                        int neighbor = adjList[node][j];
                        
                        if (!vis[neighbor]){
                            vis[neighbor] = 1;
                            parent[neighbor] = node;
                            q.push(neighbor);
                        }
                        else if (neighbor != parent[node]){
                            return true;
                        }
                    }
                }
            }
        }
        
        return false;
    }
    
    // ============= DIRECTED GRAPH CYCLE DETECTION =============
    
    // DFS approach for directed graph using color marking
    bool hasCycleDirectedGraph(){
        // WHITE = 0, GRAY = 1, BLACK = 2
        vector<int> color(numNodes, 0);
        
        for (int i = 0; i < numNodes; i++){
            if (color[i] == 0){
                if (detectCycleDFSDirected(i, color)){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    // ============= UTILITY FUNCTIONS =============
    
    void printResult(string graphType, string method, bool hasCycle){
        cout << "Graph Type: " << graphType << endl;
        cout << "Method: " << method << endl;
        cout << "Cycle Present: " << (hasCycle ? "YES" : "NO") << endl;
        cout << "----------------------------" << endl;
    }
};


void TopologicalSort(vector<vector<int>>& adjList){
    // only possible in DAG (Directed Acyclic Graph)
    // topological sort --> linear ordering such that for every directed edge u -> v, vertex u comes before vertex v in the ordering. 
    

    // My approach
    // if we add like bfs order then it's correct but if we start from the root node
    // so we kinda store the bfs order in stack and when new node comes 
    // It has two possibility either not the parent of curr node or other disconnected graph node
    // so either way we add it into the stack and ans is reverse of stack


    // basically we do dfs and when the dfs of node is node put it in the stack and if child node is already visited skip it 

    // khan's algorithm 

    // Idea is to make a Indegree array
    // insert node which have 0 degree
    // then remove that node (decrease the degree of it's neighbour)
    // if any neighbour's degree become  zero insert into the queue && store the node in result
    

}

// Dijkstra's algorithm using priority queue (min-heap)
// also use sets because set stores element in sorted order (top element is the smallest one )
// advantage is when we get a node which reach from 10 dis from a path and we get even shorter dis then there's no point in storing that 10 dis node in set so we remove it 
void Dijkstra(int start, vector<vector<pair<int, int>>>& adjList, vector<int>& dist){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for (auto& edge : adjList[u]){
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    set<pair<int, int>> s;
    s.insert({0, start});

    dist[start] = 0;
    while(!s.empty()){
        auto it = *(s.begin());
        int node = it.second;
        int dis = it.first;
        s.erase(it);

        for (auto it : adjList[node]){
            int AdjNode = it.first;
            int weight = it.second;

            if (dist[node] + weight < dist[AdjNode]){
                if (dist[AdjNode] != INT_MAX){
                    s.erase({dist[AdjNode], AdjNode});
                }
                dist[AdjNode] = dist[node] + weight;
                s.insert({dist[AdjNode], AdjNode});
            }
        }
    }

    // time complexity --> )(E log V ) where E is the number of edges and V is the number of vertices
    // why E log V ? 
}


int main(){
    
    // Example usage:
    // For undirected graph:
    // int n = 5;
    // vector<int> adj[n];
    // adj[0] = {1, 2};
    // adj[1] = {0, 3};
    // adj[2] = {0, 4};
    // adj[3] = {1};
    // adj[4] = {2};
    
    // CycleDetection cd(n, adj);
    // cout << "Undirected Graph - DFS: " << (cd.hasCycleUndirectedDFS() ? "Cycle Found" : "No Cycle") << endl;
    // cout << "Undirected Graph - BFS: " << (cd.hasCycleUndirectedBFS() ? "Cycle Found" : "No Cycle") << endl;
    
    // For directed graph:
    // int m = 4;
    // vector<int> dirAdj[m];
    // dirAdj[0] = {1};
    // dirAdj[1] = {2};
    // dirAdj[2] = {3};
    // dirAdj[3] = {1};  // Back edge: creates cycle
    
    // CycleDetection cdDir(m, dirAdj);
    // cout << "Directed Graph: " << (cdDir.hasCycleDirectedGraph() ? "Cycle Found" : "No Cycle") << endl;

    return 0;
}
#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;

// directed 
class Graph{
    public:
    unordered_map<int, list<int>> adj;

    void addEdges(int u, int v) {
        adj[u].push_back(v);
    }

    void printEdges() {
        for(auto it:adj) {
            int src = it.first;
            cout << src << ": ";
            for(auto nbr:adj[src]) {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }

    void topologicalSortDFS(int src, unordered_map<int, bool> &visited, stack<int> &order) {
        visited[src] = true;

        for(auto nbr:adj[src]) {
            if(!visited[nbr]) {
                topologicalSortDFS(nbr, visited, order);
            }
        }

        order.push(src);
        // cout << "Storing " << src << " in stack" << endl;
    }

    void topologicalSort(int V, stack<int> &order) {
        unordered_map<int, bool> visited;
        for(int src = 0; src < V; src++) {
            if(!visited[src]) {
                // cout << "Call recieved for node " << src << endl;
                topologicalSortDFS(src, visited, order);
            }
        }
    }

    void dfs(int src, unordered_map<int, list<int>> &newAdj, unordered_map<int, bool> &visited) {
        visited[src] = true;
        cout << src << " ";

        for(auto nbr:newAdj[src]) {
            if(!visited[nbr]) {
                dfs(nbr, newAdj, visited);
            }
        }
    }

    // strongly connected component
    void countSCC(int V) {
        // get topological order
        stack<int> order;
        topologicalSort(V, order);

        // reverse the edge list
        unordered_map<int, list<int>> newAdj;
        for(auto it:adj) {
            int u = it.first;
            for(auto v:adj[u]) {
                newAdj[v].push_back(u);
            }
        }

        // traverse according to the order
        unordered_map<int, bool> visited;
        int cnt = 0;
        while(!order.empty()) {
            int src = order.top();
            order.pop();

            if(!visited[src]) {
                cout << "SCC: "; 
                cnt++;
                dfs(src, newAdj, visited);
                cout << endl;
            }
        }

        cout << "Number of Strongly Connnected Component: " << cnt << endl;
    }

};

int main()
{
    Graph g;

    g.addEdges(0, 3);
    g.addEdges(3, 2);
    g.addEdges(2, 1);
    g.addEdges(1, 0);
    g.addEdges(2, 4);
    g.addEdges(4, 5);
    g.addEdges(5, 6);
    g.addEdges(6, 4);
    g.addEdges(6, 7);

    g.printEdges(); 
    
    int V = 8;
    g.countSCC(V);
    
    return 0;
}
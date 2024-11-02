#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

// undirected graph
class Graph {
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
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

    void bridgeInGraph(int src, vector<int> &tin, vector<int> &low, int parent, int timer, unordered_map<int, bool> &vis) {
        vis[src] = true;
        timer++;
        tin[src] = timer;
        low[src] = timer;

        for(auto nbr:adj[src]) {
            if(nbr == parent) continue;
            if(!vis[nbr]) {
                // DFS Search
                bridgeInGraph(nbr, tin, low, src, timer, vis);
                // Check Bridge
                if(low[nbr] > tin[src]) {
                    cout << "Bridge Found !!" << endl;
                    cout << src << "-" << nbr << endl;
                }
            }
            // update low
            low[src] = min(low[src], low[nbr]);
        }
    }

};

int main()
{
    Graph g;
    int V = 5;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(3, 2);
    g.addEdge(3, 4);

    g.printEdges();


    int src = 0;
    vector<int> tin(V , -1);
    vector<int> low(V , -1);
    int parent = -1;
    int timer = 0;
    unordered_map<int, bool> vis;

    g.bridgeInGraph(src, tin, low, parent, timer, vis);
    
    return 0;
}
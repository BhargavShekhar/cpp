#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits.h>
using namespace std;

// weighted directed Graph
class Graph{
    public:
    // <u, <v,wt>>
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdges(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        // ensure all node's are added
        if(adj.find(v) == adj.end()) {
            adj[v] = list<pair<int, int>> {};
        }
    }

    void printEdges() {
        for(auto it1:adj) {
            int node = it1.first;
            cout << node << ": ";
            for(auto it2:adj[node]) {
                int nbr = it2.first;
                int weight = it2.second;
                cout << "(" << nbr << "-> " << weight << ") ";
            }   cout << endl;
        }
    }

    bool bellmenFord(int src, int n) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // do n-1 times relaxation
        for(int i = 0; i < n-1; i++) {
            for(auto it1:adj) {
                int node = it1.first;
                for(auto it2:adj[node]) {
                    int nbrNode = it2.first;
                    int nbrWeight = it2.second;

                    if(dist[node] != INT_MAX && dist[node] + nbrWeight < dist[nbrNode]) {
                        dist[nbrNode] = dist[node] + nbrWeight;
                    }
                }
            }
        }

        for(auto it1:adj) {
            int node = it1.first;
            for(auto it2:adj[node]) {
                int nbrNode = it2.first;
                int nbrWeight = it2.second;

                if(dist[node] != INT_MAX && dist[node] + nbrWeight < dist[nbrNode]) {
                    dist = {-1};
                    return true; // -ve node or -ve cycle is present
                }
            }
        }

        cout << "Belmen Ford Result:" << endl;
        for(int i = 0; i < n; i++) {
            cout << dist[i] << " ";
        }   cout << endl;

        return false;
    }
};

int main()
{
    Graph g;

    g.addEdges(0, 1, -1);
    g.addEdges(1, 4, 2);
    g.addEdges(0, 2, 4);
    g.addEdges(3, 2, 5);
    g.addEdges(4, 3, -3);
    g.addEdges(1, 2, 3);
    g.addEdges(1, 3, 2);
    g.addEdges(3, 1, 1);

    g.printEdges();

    bool negCycle = g.bellmenFord(0, 5);
    if(negCycle) cout << "Negetive Cycle Present" << endl;
    
    return 0;
}
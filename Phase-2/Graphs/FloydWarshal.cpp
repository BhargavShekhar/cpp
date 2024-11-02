#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

// directed weighted graph
class Graph{
    public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdges(int u, int v, int weight) {
        adj[u].push_back({v, weight});
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

    // mssp
    void floidWarshal(int V) {
        vector<vector<int>> dist(V, vector<int>(V, 1e9));
        // initialize same node dist
        for(int i = 0; i < V; i++) {
            dist[i][i] = 0;
        }
        // initialize other node's dist
        for(auto it1:adj) {
            int node = it1.first;
            for(auto it2:adj[node]) {
                int nbr = it2.first;
                int weight = it2.second;
                dist[node][nbr] = weight;
            }
        }
        // main logic
        for(int helper = 0; helper < V; helper++) {
            for(int u = 0; u < V; u++) {
                for(int v = 0; v < V; v++) {
                    dist[u][v] = min(dist[u][v], dist[u][helper] + dist[helper][v]);
                }
            }
        }

        // print solution
        cout << "Result of FLoydWarshal Algo:" << endl;
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                cout << dist[i][j] << " ";
            }   cout << endl;
        }
    }
};

int main()
{
    Graph g;

    g.addEdges(0, 2, -2);
    g.addEdges(2, 3, 2);
    g.addEdges(3, 1, -1);
    g.addEdges(1, 2, 3);
    g.addEdges(1, 0, 4);

    g.printEdges();

    int V = 4;
    g.floidWarshal(V);
    
    return 0;
}
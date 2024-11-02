#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;

// undirected weighted graph
class Graph{
    public:
    unordered_map<int, list<pair<int, int>>> adj;  // u, <v, wt>

    void addEdges(int u, int v, int wt) {
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    void printEdges() {
        for(auto it1:adj) {
            int node = it1.first;
            cout << node << ": ";
            for(auto it2:it1.second) {
                int nbr = it2.first;
                int weight = it2.second;
                cout << "(" << nbr << "-> " << weight << ") ";
            }   cout << endl;
        }
    }

    void dijkstra(int src, int n) {
        // <weight, node>
        set<pair<int, int>> st;

        vector<int> dist(n+1, INT_MAX);

        dist[src] = 0;

        st.insert({0, src});

        while(!st.empty()) {
            // fetch element from set
            auto topElem = *(st.begin()); // dref to get the top elem
            int topNodeDis = topElem.first;
            int topNode = topElem.second;
            
            // remove element
            st.erase(st.begin());

            for(auto it:adj[topNode]) {
                // adjlist[u] -> List of pair<node, weight>
                int nbrNode = it.first;
                int nbrDis = it.second;

                if(dist[topNode] + nbrDis < dist[nbrNode]) {
                    auto result = st.find({dist[nbrNode], nbrNode});
                    if(result != st.end()) {
                        st.erase(result);
                    }

                    dist[nbrNode] = dist[topNode] + nbrDis;
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }

        cout << "Dijkstra Sortest Path:" << endl;
        for(int i = 0; i < n; i++) {
            cout << dist[i] << " ";
        }   cout << endl;
    }
};

int main()
{
    Graph g;

    g.addEdges(0, 5, 9);
    g.addEdges(0, 3, 6);
    g.addEdges(1, 2, 7);
    g.addEdges(2, 3, 15);
    g.addEdges(3, 4, 11);
    g.addEdges(4, 1, 9);
    g.addEdges(4, 2, 10);
    g.addEdges(5, 4, 2);
    g.addEdges(5, 1, 14);

    g.printEdges();

    g.dijkstra(0, 6);
    
    return 0;
}
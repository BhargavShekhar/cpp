#include<iostream>
#include<unordered_map>
#include<stack>
#include<list>
#include<vector>
#include<limits.h>
using namespace std;

// Directed Weighted Graph
class Graph{
    public:
        // node -> (nbr, weight)
        unordered_map<int, list<pair<int, int>>> adj;

        void addEdges(int u, int v, int weight) {
            adj[u].push_back({v, weight});
            // To ensure all nodes are consideres as src
            if(adj.find(v) == adj.end()) {
                adj[v] = list<pair<int, int>> {};
            }
        }

        void printEdges() {
            for(auto it:adj) {
                int node = it.first;
                cout << node << ": ";
                for(auto it2:adj[node]) {
                    int nbr = it2.first;
                    int weight = it2.second;
                    cout << nbr << "-> " << weight << ", ";
                }
                cout << endl;
            }
        }

        void topologicalSortHelper(int src, stack<int> &order, unordered_map<int, bool> &visited) {
            visited[src] = true;

            for(auto it:adj[src]) {
                int nbr = it.first;
                if(!visited[nbr]) {
                    topologicalSortHelper(nbr, order, visited);
                }
            }

            order.push(src);
        }

        void topologicalSort(stack<int> &order) {
            unordered_map<int, bool> visited;
            for(auto it:adj) {
                int node = it.first;
                if(!visited[node]) {
                    topologicalSortHelper(node, order, visited);
                }
            }
        }

        void shortestPathDFS() {
            stack<int> topoOrder;
            topologicalSort(topoOrder);

            int n = topoOrder.size();
            vector<int> distance(n, INT_MAX);

            int src = topoOrder.top();
            topoOrder.pop();

            // maintain initial state
            distance[src] = 0;

            // update min ditance of nbr's of src
            for(auto it:adj[src]) {
                int nbr = it.first;
                int weight = it.second;

                if(distance[src] + weight < distance[nbr]) {
                    distance[nbr] = distance[src] + weight;
                }
            }

            // update rest of the node's nbr
            while(!topoOrder.empty()) {
                int node = topoOrder.top();
                topoOrder.pop();

                for(auto it:adj[node]) {
                    int nbr = it.first;
                    int weight = it.second;

                    if(distance[node] + weight < distance[nbr]) {
                        distance[nbr] = distance[node] + weight;
                    }
                }
            }

            // print distance vector
            cout << "Distance Array: ";
            for(auto elem:distance) {
                cout << elem << " ";
            }   cout << endl;
        }

};

int main()
{
    Graph g;

    // u, v, weight
    g.addEdges(0, 2, 13);
    g.addEdges(0, 1, 5);
    g.addEdges(0, 4, 3);
    g.addEdges(1, 4, 1);
    g.addEdges(1, 2, 7);
    g.addEdges(4, 3, 6);
    g.addEdges(3, 2, 2);

    // g.printEdges();

    g.shortestPathDFS();

    return 0;
}
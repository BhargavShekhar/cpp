#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<pair<int, int>>> adjList;

        void addEdge(int u, int v, int weight, bool direction) {
            // direction = 0 -> undirected graph
            // direction = 1 -> directed graph
            if(direction == 0) {
                adjList[u].push_back({v, weight});
                adjList[v].push_back({u, weight});
            }
            else {
                adjList[u].push_back({v, weight});
            }
        }

        void printAdjList(int n) {
            for(int i = 0; i < n; i++) {
                cout << i << " : ";
                cout << "{";
                list<pair<int, int>> temp = adjList[i];
                for(auto j:temp) {
                    int node = j.first;
                    int weight = j.second;
                    cout << "(";
                    cout << node << ", " << weight;
                    cout << "),";
                }
                cout << "}" << endl;
            }
        }
};

int main()
{
    Graph g;

    g.addEdge(0, 1, 3, 1); // 0 se 1 ek edge hai with distance/weight 3 and is directional graph
    g.addEdge(0, 2, 4, 1);
    g.addEdge(1, 2, 1, 1);
    g.addEdge(2, 3, 16, 1);

    g.printAdjList(4);
    
    return 0;
}
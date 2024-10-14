#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

class Graph {
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

        void bfsTraversal(int srcNode) {
            queue<int> q;
            unordered_map<int, bool> visited;

            q.push(srcNode);
            visited[srcNode] = true;

            while(!q.empty()) {
                int frontNode = q.front();
                q.pop();

                cout << frontNode << " ";

                for(auto neighbour:adjList[frontNode]) {
                    int node = neighbour.first;
                    int weight = neighbour.second;

                    if(!visited[node]) {
                        q.push(node);
                        visited[node] = true;
                    }
                }
            }
        }

        void dfsHelper(int srcNode, unordered_map<int, bool> &visited) {
            visited[srcNode] = true;
            cout << srcNode << " ";

            for(auto neighnour:adjList[srcNode]) {
                int node = neighnour.first;
                if(!visited[node]) {
                    dfsHelper(node, visited); 
                }
            }
        }

        void dfsTraversal(int totalNodes) {
            int srcNode = 0;
            unordered_map<int, bool> visited;
            dfsHelper(srcNode, visited);
        }
};

int main()
{
    Graph g;

    g.addEdge(0,3,3,1);
    g.addEdge(0,5,3,1);
    g.addEdge(0,2,3,1);
    g.addEdge(2,5,3,1);
    g.addEdge(3,5,3,1);
    g.addEdge(5,4,3,1);
    g.addEdge(5,6,3,1);
    g.addEdge(4,1,3,1);
    g.addEdge(6,1,3,1);

    cout << "Graph:";
    cout << endl;

    g.printAdjList(7);

    cout << endl;
    cout << "Bfs Traversal:";
    cout << endl;

    g.bfsTraversal(0);  // 0 3 5 2 4 6 1

    cout << endl;
    cout << "Dfs Traversal:";
    cout << endl;

    g.dfsTraversal(7);
    
    return 0;
}
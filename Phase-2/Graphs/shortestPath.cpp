#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<int>> adjList;

        void addEdges(int u, int v) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        void printEdges() {
            for(auto srcNode:adjList) {
                cout << srcNode.first << ": ";
                for(auto nbr:adjList[srcNode.first]) {
                    cout << nbr << ", ";
                }
                cout << endl;
            }
        }

        void shortestPath(int src, int dest) {
            unordered_map<int, bool> visited;
            unordered_map<int, int> parent;

            queue<int> q;

            q.push(src);
            visited[src] = true;
            parent[src] = -1;

            // BFS Traversal
            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(auto nbr:adjList[node]) {
                    if(!visited[nbr]) {
                        visited[nbr] = true;
                        parent[nbr] = node;
                        q.push(nbr);
                    }
                }
            }

            // get the shortest path
            vector<int> path;
            path.push_back(dest);

            while(parent[dest] != -1) {
                int parentNode = parent[dest];
                path.push_back(parentNode);
                dest = parentNode;
            }

            // print the sortest path
            for(int i = path.size()-1; i >= 0; i--) {
                cout << path[i] << " ";
            }   cout << endl;
        }
};



int main()
{
    Graph g;

    g.addEdges(0, 1);
    g.addEdges(1, 2);
    g.addEdges(2, 3);
    g.addEdges(2, 4);
    g.addEdges(4, 5);
    g.addEdges(5, 3);

    // g.printEdges();

    g.shortestPath(0, 3); // 0 1 2 3
    
    return 0;
}
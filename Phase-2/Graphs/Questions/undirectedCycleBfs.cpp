// Detect if cycle is present in the undirected Graph
// solve it in gfg
#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<int>> adjList;

        void addEdge(int u, int v) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        void printAdjList() {
            for(auto it:adjList) {
                int node = it.first;
                list<int> lst = it.second;

                cout << node << " -> {";

                for(auto it2:lst) {
                    cout << it2 << ",";
                }

                cout << "}" << endl;
            }
        }

        bool isCycle(int srcNode, unordered_map<int, bool> &visited) {
            queue<int> queueNode;
            unordered_map<int, int> parent;

            queueNode.push(srcNode);
            visited[srcNode] = true;
            parent[srcNode] = -1;

            while(!queueNode.empty()) {
                int currentNode = queueNode.front();
                queueNode.pop();

                for(auto neighbour:adjList[currentNode]) {
                    if(visited[neighbour] && neighbour != parent[currentNode]) return true;
                    if(!visited[neighbour]) {
                        queueNode.push(neighbour);
                        visited[neighbour] = true;
                        parent[neighbour] = currentNode;
                    }
                }
            }

            return false;
        }

        // we have to check for all nodes since graph can be dissconnected also
        bool detectCycle() {
            unordered_map<int, bool> visited;

            for(auto nodePair:adjList) {
                int node = nodePair.first;
                if(!visited[node]) {
                    if(isCycle(node, visited)) return true;
                }
            }

            return false;
        }
};

int main()
{
    Graph g;

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,5);
    g.addEdge(5,4);
    g.addEdge(5,6);
    g.addEdge(6,4);
    g.addEdge(3,4);

    g.printAdjList();

    cout << "Is Cycle Present in Graph1: " << g.detectCycle() << endl;

    Graph g2;

    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 4);

    g2.printAdjList();

    cout << "Is Cycle Present in Graph2: " << g2.detectCycle() << endl;
    
    return 0;
}
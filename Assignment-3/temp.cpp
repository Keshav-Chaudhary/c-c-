#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjacencyList;

public:
    Graph(int numVertices) : adjacencyList(numVertices) {}

    void addEdge(int from, int to) {
        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from);
    }

    void DFS(int startNode) {
        vector<bool> visited(adjacencyList.size(), false);
        DFSUtil(startNode, visited);
    }

    void BFS(int startNode) {
        vector<bool> visited(adjacencyList.size(), false);
        queue<int> q;
        visited[startNode] = true;
        q.push(startNode);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adjacencyList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

private:
    void DFSUtil(int current, vector<bool>& visited) {
        visited[current] = true;
        cout << current << " ";

        for (int neighbor : adjacencyList[current]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }
};

int main() {
    Graph graph(4);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    cout << "Depth-First Search (DFS): ";
    graph.DFS(0);
    cout << endl;

    cout << "Breadth-First Search (BFS): ";
    graph.BFS(0);

    return 0;
}

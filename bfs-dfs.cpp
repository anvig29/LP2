#include <iostream>
#include <queue>
using namespace std;

#define MAX_VERTICES 100

class Graph {
    int V; 
    int adj[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix

public:
    Graph(int V);
    void addEdge(int u, int v);
    void DFS(int v, bool visited[]);
    void BFS(int v);
};

Graph::Graph(int V) {
    this->V = V;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            adj[i][j] = 0;
        }
    }
}

void Graph::addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; // Assuming undirected graph
}

void Graph::DFS(int v, bool visited[]) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < V; ++i) {
        if (adj[v][i] && !visited[i]) {
            DFS(i, visited);
        }
    }
}

void Graph::BFS(int v) {
    bool visited[MAX_VERTICES] = {false};
    queue<int> q;

    visited[v] = true;
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        cout << v << " ";
        q.pop();

        for (int i = 0; i < V; ++i) {
            if (adj[v][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int src_dfs;
    cout << "Enter source vertex for DFS traversal: ";
    cin >> src_dfs;

    cout << "DFS Traversal: ";
    bool visited[MAX_VERTICES] = {false};
    g.DFS(src_dfs, visited);
    cout << endl;

    int src_bfs;
    cout << "Enter source vertex for BFS traversal: ";
    cin >> src_bfs;

    cout << "BFS Traversal: ";
    g.BFS(src_bfs);
    cout << endl;

    return 0;
}

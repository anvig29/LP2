#include <iostream>
#include <climits>
using namespace std;

void printPath(int parent[], int j) {
    if (parent[j] == -1){
        std::cout << j << " ";
        return;
    }
    printPath(parent, parent[j]);
    std::cout << j << " ";
}
void dijkstra(int** graph, int V, int src, int dest) {
    int dist[V];
    bool visited[V];
    int parent[V];

    for (int i = 0; i < V; ++i) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int minDist = INT_MAX, minIndex;

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && dist[v] <= minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }

        int u = minIndex;
        visited[u] = true;

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest Path from " << src << " to " << dest << ": ";
    printPath(parent, dest);
    cout << endl;
    
    cout << "Minimum Weight of Path: " << dist[dest] << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    int** graph = new int*[V];
    for (int i = 0; i < V; ++i) {
        graph[i] = new int[V];
        for (int j = 0; j < V; ++j)
            graph[i][j] = 0;
    }

    cout << "Enter edges with weights (source, destination, weights):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // If the graph is undirected
    }
    int src, dest;
    cout << "Enter the source vertex: ";
    cin >> src;
    cout << "Enter the destination vertex: ";
    cin >> dest;
    dijkstra(graph, V, src, dest);
    
    return 0;
}

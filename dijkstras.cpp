#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;
void printPath(vector<int>& parent, int j) {
    if (parent[j] == -1){
        std::cout << j << " ";
        return;
    }
    printPath(parent, parent[j]);
    std::cout << j << " ";
}
void dijkstra(vector<vector<int> >& graph, int src, int dest) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);

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
    //cout << dest << endl;
    cout<<endl;
    
    cout << "Minimum Weight of Path: " << dist[dest] << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<vector<int> > graph(V, vector<int>(V, 0));

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
    dijkstra(graph, src, dest);
    return 0;
}

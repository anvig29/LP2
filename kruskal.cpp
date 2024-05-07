#include <iostream>
#include <algorithm>
using namespace std;
// DSU data structure
// path compression + rank by union
class DSU {
    int* parent;
    int* rank;
    int size;

public:
    DSU(int n) {
        size = n;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find function
    int find(int i) {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    // Union function
    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            }
            else {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};
class Graph {
    int** edgelist;
    int V;
    int E;
public:
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        edgelist = new int*[E];
        for (int i = 0; i < E; ++i) {
            edgelist[i] = new int[3];
        }
    }

    // Function to add edge in a graph
    void addEdge(int x, int y, int w, int index) {
        edgelist[index][0] = w;
        edgelist[index][1] = x;
        edgelist[index][2] = y;
    }

    void kruskals_mst() {
        // Sort all edges
 sort(edgelist, edgelist + E);
        // Initialize the DSU
        DSU s(V);
        int ans = 0;
        cout << "Following are the edges in the constructed MST" << endl;
        for (int i = 0; i < E; ++i) {
            int w = edgelist[i][0];
            int x = edgelist[i][1];
            int y = edgelist[i][2];

            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
                cout << x << " -- " << y << " == " << w << endl;
            }
        }
        cout << "Minimum Cost Spanning Tree: " << ans;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph g(V, E);
    cout << "Enter the edges and their weights (format: u v w):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w, i);
    }

    // Function call
    g.kruskals_mst();
    return 0;
}

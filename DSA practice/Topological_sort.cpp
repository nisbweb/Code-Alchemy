#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack, const vector<vector<int>>& adj) {
    visited[v] = true;

    // Recur for all vertices adjacent to this vertex
    for (int u : adj[v]) {
        if (!visited[u]) {
            topologicalSortUtil(u, visited, Stack, adj);
        }
    }

    // Push current vertex to stack after all its adjacent vertices are processed
    Stack.push(v);
}

void topologicalSort(int V, const vector<vector<int>>& adj) {
    stack<int> Stack;
    vector<bool> visited(V, false);

    // Call the recursive helper function for all unvisited vertices
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, Stack, adj);
        }
    }

    // Print the topological ordering
    cout << "Topological Sort Order: ";
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter the edges (u v) for directed edges:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Add edge u -> v
    }

    topologicalSort(V, adj);
    return 0;
}

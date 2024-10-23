/*
    The network chamber is in disarray, with several communication paths between nodes broken. 
    The network is represented as an undirected graph where nodes represent servers, and edges represent communication links between them. 
    Your task is to restore stable connectivity by finding the shortest path between two specific nodes. You must also ensure there are no network loops by resolving any cycles.

    To fix the network:
    Find the shortest path between two given nodes (servers) using Dijkstra’s algorithm.
    Ensure that the network is loop-free by removing any cycles in the graph.

    Input:
    n: The number of nodes (servers) in the network.
    edges: A list of tuples representing the communication links between nodes. 
          Each tuple is in the format (u, v, w), where u and v are nodes, and w is the weight of the edge (representing the cost of communication between them).
    source: The starting node (server) from which to calculate the shortest path.
    target: The destination node (server) where communication needs to be restored.

    Output:
    The shortest path between the source and target nodes.
    The total cost (sum of weights) of the shortest path.

    Example
    Input
    n = 6
    edges = [
        {0, 1, 4},
        {0, 2, 1},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 8},
        {3, 4, 3},
        {4, 5, 7}
    ]
    source = 0
    target = 5

    Output
    Shortest Path: [0, 2, 1, 3, 4, 5]
    Total Cost: 18
*/

// WRITE YOUR CODE HERE

#include <bits/stdc++.h>

using namespace std;

pair<vector<int>, int> dijkstra(int n, vector<pair<int, int>> adj[], int source, int target) {
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    vector<int> path;
    for (int v = target; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    if (path[0] != source) {
        return {};
    }

    return {path, dist[target]};
}

void remove_cycles(int u, vector<pair<int, int>> adj[], vector<bool> &visited, set<pair<int, int>> &edges) {
    visited[u] = true;

    for (auto edge : adj[u]) {
        int v = edge.first;
        if (visited[v]) {
            edges.erase(minmax(u, v));
        }
        else {
            remove_cycles(v, adj, visited, edges);
        }
    }
}

int main() {
    int n = 6;
    vector<pair<int, int>> adj[6];
    vector<tuple<int, int, int>> edges = {
        {0, 1, 4}, {0, 2, 1}, {1, 2, 2}, {1, 3, 5},
        {2, 3, 8}, {3, 4, 3}, {4, 5, 7}
    };

    for (auto edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source = 0;
    int target = 5;

    set<pair<int, int>> edges_set;
    for (auto edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;
        edges_set.insert(minmax(u, v));
    }

    vector<bool> visited(n, false);
    remove_cycles(source, adj, visited, edges_set);

    auto result = dijkstra(n, adj, source, target);
    vector<int> shortest_path = result.first;
    int total_cost = result.second;

    if (shortest_path.empty()) {
        cout << "No path found from " << source << " to " << target << endl;
    }
    else {
        cout << "Shortest path: ";
        for (int node : shortest_path) {
            cout << node << " ";
        }
        cout << endl;
        cout << "Total cost: " << total_cost << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MAX_N = 100;

vector<int> adj[MAX_N];  // Adjacency list
bool visited[MAX_N];  // Visited array

// DFS function
void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    // Build the graph: two points are connected if they share x or y
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (points[i].first == points[j].first || points[i].second == points[j].second) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // Count connected components
    int components = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i);
        }
    }

    // Minimum additional snow drifts needed
    cout << (components - 1) << endl;

    return 0;
}

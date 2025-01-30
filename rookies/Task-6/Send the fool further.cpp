#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int max_N = 100;
vector<pair<int, int>> adj[max_N];
bool visited[max_N];
int maxCost = 0;
void dfs(int node, int currentCost) {
    visited[node] = true;
    maxCost = max(maxCost, currentCost);
    for (auto &neighbor : adj[node]) {
        int nextNode = neighbor.first;
        int cost = neighbor.second;
        if (!visited[nextNode]) {
            dfs(nextNode, currentCost + cost);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }


    memset(visited, false, sizeof(visited));
    dfs(0, 0);

    cout << maxCost << endl;

    return 0;
}

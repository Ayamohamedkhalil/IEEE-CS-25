#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int max_N = 100;

vector<int> adj[max_N];
bool visited[max_N];


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


    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (points[i].first == points[j].first || points[i].second == points[j].second) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }


    int components = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i);
        }
    }
    cout << (components - 1) << endl;

    return 0;
}

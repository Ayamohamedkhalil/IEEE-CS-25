#include <iostream>
#include <vector>

using namespace std;

const int max_N = 100005;
vector<int> adj[max_N];
int cat[max_N];
int n, m, validRestaurants = 0;


void dfs(int node, int parent, int consecutiveCats) {
    if (cat[node]) {
        consecutiveCats++;
    } else {
        consecutiveCats = 0;
    }


    if (consecutiveCats > m) {
        return;
    }


    bool isLeaf = true;
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            isLeaf = false;
            dfs(neighbor, node, consecutiveCats);
        }
    }


    if (isLeaf) {
        validRestaurants++;
    }
}

int main() {
    cin >> n >> m;


    for (int i = 1; i <= n; i++) {
        cin >> cat[i];
    }


    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    dfs(1, -1, 0);

    cout << validRestaurants << endl;
    return 0;
}

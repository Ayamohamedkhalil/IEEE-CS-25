#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;


int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y) {

    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || grid[x][y] == 0)
        return 0;

    visited[x][y] = true;
    int volume = grid[x][y];


    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        volume += dfs(nx, ny);
    }

    return volume;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        grid.assign(n, vector<int>(m));
        visited.assign(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        int max_volume = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] > 0) {
                    max_volume = max(max_volume, dfs(i, j));
                }
            }
        }

        cout << max_volume << "\n";
    }

    return 0;
}

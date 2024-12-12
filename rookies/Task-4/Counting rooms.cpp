#include <iostream>
#include <vector>
#include <queue>
using namespace std;


 int dx[4] = {-1, 1, 0, 0};
 int dy[4] = {0, 0, -1, 1};

void bfs(int startx, int starty, vector<vector<bool>> &visited,vector<string> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({startx, starty});
    visited[startx][starty] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();


        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];


            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int rooms = 0;


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            if (grid[i][j] == '.' && !visited[i][j]) {
                bfs(i, j, visited, grid);
                ++rooms;
            }
        }
    }

    cout << rooms << endl;
    return 0;
}

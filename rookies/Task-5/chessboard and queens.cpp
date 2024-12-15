#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n= 8;
vector<string> board;
int solutions= 0;
vector<bool> col(n,false), diag1(2*n,false),diag2(2*n,false);

void solve(int row) {
    if (row==n) {
        solutions++;
        return;
    }

    for (int c=0; c<n; c++) {
        if (board[row][c] == '.' && !col[c] && !diag1[row-c+n] && !diag2[row+c]) {
            col[c] = diag1[row-c+n]= diag2[row+c]=true;
            solve(row+1);
            col[c]=diag1[row-c+n]=diag2[row+c] = false;
        }
    }
}

int main() {
    board.resize(n);
    for (int i=0; i<n; i++) {
    cin >> board[i];
    }
    solve(0);
    cout <<solutions<< endl;

    return 0;
}

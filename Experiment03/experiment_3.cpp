#include <bits/stdc++.h>

using namespace std;

vector<string> board;
vector<vector<string>> result;
int sz;
vector<bool> cols;
vector<bool> posDiag;
vector<bool> negDiag;

bool isValid(int r, int c) {
    if (cols[c] || posDiag[r + c] || negDiag[r - c + sz]) return false;
    return true;
}

void solve(int row) {
    if (row == sz) {
        result.push_back(board);
        return;
    }
    for (int col = 0; col < sz; col++) {
        if (isValid(row, col)) {
            board[row][col] = 'Q';
            cols[col] = posDiag[row + col] = negDiag[row - col + sz] = true;
            
            solve(row + 1);
            
            board[row][col] = '.';
            cols[col] = posDiag[row + col] = negDiag[row - col + sz] = false;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    sz = n;
    board = vector<string>(n, string(n, '.'));
    cols.assign(n, false);
    posDiag.assign(2 * n, false);
    negDiag.assign(2 * n, false);
    solve(0);
    return result;
}

int main()
{
    solveNQueens(3);
    return 0;
}

// COMPLEXITY FOR VALIDATING SAFE STATE IS O(1)

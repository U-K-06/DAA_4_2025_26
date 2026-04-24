#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<string>> solutions;

void printBoard(vector<int> &board) {
    vector<string> temp(n, string(n, '.'));

    for (int i = 0; i < n; i++) {
        temp[i][board[i]] = 'Q';
    }

    solutions.push_back(temp);
}

void solve(int row, vector<int> &board,
           vector<bool> &cols,
           vector<bool> &diag1,
           vector<bool> &diag2) {

    if (row == n) {
        printBoard(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (cols[col] || diag1[row - col + n - 1] || diag2[row + col])
            continue;

        board[row] = col;
        cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

        solve(row + 1, board, cols, diag1, diag2);

        cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
    }
}

int main() {
    cout << "Enter N: ";
    cin >> n;

    vector<int> board(n);
    vector<bool> cols(n, false);
    vector<bool> diag1(2 * n - 1, false);
    vector<bool> diag2(2 * n - 1, false);

    solve(0, board, cols, diag1, diag2);

    cout << "\nTotal Solutions: " << solutions.size() << "\n\n";

    for (auto &sol : solutions) {
        for (auto &row : sol) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
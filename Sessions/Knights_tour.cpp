#include <vector>
using namespace std;

class Solution {
  public:
    bool isSafe(int r, int c, int n, vector<vector<int>>& board) {
        return r >= 0 && r < n && c >= 0 && c < n && board[r][c] == -1;
    }

    bool solve(int r, int c, int move, vector<vector<int>>& board, int n) {
        if (move == n * n) return true;
        vector<int> dx = {-2, -1, 1, 2, 2, 1, -1, -2};
        vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};
        for (int i = 0; i < 8; i++) {
            int nx = r + dx[i];
            int ny = c + dy[i];
            if (isSafe(nx, ny, n, board)) {  
                board[nx][ny] = move;
                if (solve(nx, ny, move + 1, board, n)) return true;
                board[nx][ny] = -1;
            }
        }
        return false;
    }


    vector<vector<int>> knightTour(int n) {
        vector<int> temp(n, -1);
        vector<vector<int>> board(n, temp);
        board[0][0] = 0;
        if (solve(0, 0, 1, board, n)) return board;
        return {};
    }
};

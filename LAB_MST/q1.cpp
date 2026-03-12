
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int r , int c)
    {
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visited[r][c] || board[r][c] != word[0])
        {
            return false;
        }
        if(word.size() == 1)
        {
            return true;
        }
        visited[r][c] = true;
        string nextWord = word.substr(1);
        bool found = dfs(board, visited, nextWord, r + 1, c) ||
                     dfs(board, visited, nextWord, r - 1, c) ||
                     dfs(board, visited, nextWord, r, c + 1) ||
                     dfs(board, visited, nextWord, r, c - 1);
        visited[r][c] = false;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, visited, word, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};


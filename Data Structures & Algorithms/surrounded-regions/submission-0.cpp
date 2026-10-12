
class Solution {
public:
    int m, n;

    void dfs(int r, int c, vector<vector<char>>& board) {
        if (r < 0 || r >= m || c < 0 || c >= n ||
            board[r][c] != 'O') {
            return;
        }

        board[r][c] = '#';

        dfs(r - 1, c, board);
        dfs(r + 1, c, board);
        dfs(r, c - 1, board);
        dfs(r, c + 1, board);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for (int r = 0; r < m; r++) {
            dfs(r, 0, board);
            dfs(r, n - 1, board);
        }

        for (int c = 0; c < n; c++) {
            dfs(0, c, board);
            dfs(m - 1, c, board);
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
            }
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == '#')
                    board[r][c] = 'O';
            }
        }
    }
};
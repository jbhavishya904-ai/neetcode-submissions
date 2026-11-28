
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        function<int(int, int)> dfs = [&](int i, int j) {
            if (dp[i][j] != 0)
                return dp[i][j];

            dp[i][j] = 1;

            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x >= 0 && x < m && y >= 0 && y < n &&
                    matrix[x][y] > matrix[i][j]) {

                    dp[i][j] = max(dp[i][j], 1 + dfs(x, y));
                }
            }

            return dp[i][j];
        };

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j));
            }
        }

        return ans;
    }
};

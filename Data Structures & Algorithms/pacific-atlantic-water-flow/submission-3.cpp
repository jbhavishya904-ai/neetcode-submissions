
class Solution {
public:
    int m, n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        function<void(int, int, vector<vector<bool>>&)> dfs =
        [&](int r, int c, vector<vector<bool>>& visited) {
            visited[r][c] = true;

            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    !visited[nr][nc] &&
                    heights[nr][nc] >= heights[r][c]) {
                    dfs(nr, nc, visited);
                }
            }
        };

        for (int c = 0; c < n; c++)
            dfs(0, c, pacific);

        for (int r = 0; r < m; r++)
            dfs(r, 0, pacific);

        for (int c = 0; c < n; c++)
            dfs(m - 1, c, atlantic);

        for (int r = 0; r < m; r++)
            dfs(r, n - 1, atlantic);

        vector<vector<int>> result;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};

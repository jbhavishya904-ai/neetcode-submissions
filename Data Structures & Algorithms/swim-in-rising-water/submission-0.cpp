
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        vector<vector<int>> visited(n, vector<int>(n, 0));

        pq.push({grid[0][0], {0, 0}});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int time = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            if (visited[r][c]) continue;
            visited[r][c] = 1;

            if (r == n - 1 && c == n - 1)
                return time;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    !visited[nr][nc]) {

                    pq.push({
                        max(time, grid[nr][nc]),
                        {nr, nc}
                    });
                }
            }
        }

        return -1;
    }
};

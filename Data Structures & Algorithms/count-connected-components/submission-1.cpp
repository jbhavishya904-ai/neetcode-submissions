class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int count = 0;

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i);
            }
        }

        return count;
    }
};

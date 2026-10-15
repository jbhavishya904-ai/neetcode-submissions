
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }

        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        function<bool(int, int)> dfs = [&](int node, int parent) {
            visited[node] = true;

            for (int neighbor : adj[node]) {
                if (neighbor == parent) {
                    continue;
                }

                if (visited[neighbor]) {
                    return false;
                }

                if (!dfs(neighbor, node)) {
                    return false;
                }
            }

            return true;
        };

        if (!dfs(0, -1)) {
            return false;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }
};

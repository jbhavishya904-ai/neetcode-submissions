class Solution {
public:
    vector<int> parent, size;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return false;

        if (size[pu] < size[pv])
            swap(pu, pv);

        parent[pv] = pu;
        size[pu] += size[pv];

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (!unite(u, v))
                return edge;
        }

        return {};
    }
};
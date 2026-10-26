
class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        // Include every character
        for (string &word : words) {
            for (char c : word) {
                adj[c];
                indegree[c] = 0;
            }
        }

        // Build the graph
        for (int i = 0; i < words.size() - 1; i++) {
            string a = words[i];
            string b = words[i + 1];

            int j = 0;
            while (j < a.size() && j < b.size()
                   && a[j] == b[j]) {
                j++;
            }

            // Invalid prefix case
            if (j == b.size() && a.size() > b.size()) {
                return "";
            }

            if (j < a.size() && j < b.size()) {
                char u = a[j];
                char v = b[j];

                if (adj[u].insert(v).second) {
                    indegree[v]++;
                }
            }
        }

        // Topological sort using BFS
        queue<char> q;

        for (auto &p : indegree) {
            if (p.second == 0) {
                q.push(p.first);
            }
        }

        string ans = "";

        while (!q.empty()) {
            char u = q.front();
            q.pop();
            ans += u;

            for (char v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Cycle detected
        if (ans.size() != indegree.size()) {
            return "";
        }

        return ans;
    }
};
    
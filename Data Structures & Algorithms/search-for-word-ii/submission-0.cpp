
class Solution {
    struct TrieNode {
        TrieNode* children[26]{};
        string word = "";
    };

    TrieNode* root = new TrieNode();

    void insert(string& word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c,
             TrieNode* node, vector<string>& result) {
        char ch = board[r][c];

        if (ch == '#' || !node->children[ch - 'a']) {
            return;
        }

        node = node->children[ch - 'a'];

        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";
        }

        board[r][c] = '#';

        int rows = board.size();
        int cols = board[0].size();

        if (r > 0)
            dfs(board, r - 1, c, node, result);

        if (r + 1 < rows)
            dfs(board, r + 1, c, node, result);

        if (c > 0)
            dfs(board, r, c - 1, node, result);

        if (c + 1 < cols)
            dfs(board, r, c + 1, node, result);

        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        for (string& word : words) {
            insert(word);
        }

        vector<string> result;
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, i, j, root, result);
            }
        }

        return result;
    }
};

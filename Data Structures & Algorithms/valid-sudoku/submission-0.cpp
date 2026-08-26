class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // rows[i] stores numbers already seen in row i
        // cols[j] stores numbers already seen in column j
        // boxes[k] stores numbers already seen in 3x3 box k

        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                // Ignore empty cells
                if (board[i][j] == '.')
                    continue;

                char num = board[i][j];

                // Find which 3x3 box this cell belongs to
                int box = (i / 3) * 3 + (j / 3);

                // Check for duplicate
                if (rows[i].count(num) ||
                    cols[j].count(num) ||
                    boxes[box].count(num)) {
                    return false;
                }

                // Add number to row, column and box
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[box].insert(num);
            }
        }

        return true;
    }
};
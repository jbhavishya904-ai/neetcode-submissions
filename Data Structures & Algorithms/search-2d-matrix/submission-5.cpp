class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = 0;
        int bottom = rows - 1;

        // Find the row
        while (top <= bottom) {
            int row = top + (bottom - top) / 2;

            if (target > matrix[row][cols - 1]) {
                top = row + 1;
            }
            else if (target < matrix[row][0]) {
                bottom = row - 1;
            }
            else {
                // target can be in this row
                int left = 0;
                int right = cols - 1;

                // Binary search in this row
                while (left <= right) {
                    int mid = left + (right - left) / 2;

                    if (matrix[row][mid] == target) {
                        return true;
                    }
                    else if (matrix[row][mid] < target) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }

                return false;
            }
        }

        return false;
    }
};
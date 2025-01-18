class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> result;
    if (matrix.empty()) return result;

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right along the top row
        for (int col = left; col <= right; ++col) {
            result.push_back(matrix[top][col]);
        }
        ++top;

        // Traverse from top to bottom along the right column
        for (int row = top; row <= bottom; ++row) {
            result.push_back(matrix[row][right]);
        }
        --right;

        // Traverse from right to left along the bottom row (if still valid)
        if (top <= bottom) {
            for (int col = right; col >= left; --col) {
                result.push_back(matrix[bottom][col]);
            }
            --bottom;
        }

        // Traverse from bottom to top along the left column (if still valid)
        if (left <= right) {
            for (int row = bottom; row >= top; --row) {
                result.push_back(matrix[row][left]);
            }
            ++left;
        }
    }

    return result;
    }
};
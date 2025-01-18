class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
            // Create arrays of hash sets for rows, columns, and boxes
    vector<unordered_set<char>> rowSets(9);
    vector<unordered_set<char>> colSets(9);
    vector<unordered_set<char>> boxSets(9);
    
    // Iterate through the board
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            char num = board[row][col];
            if (num == '.') continue; // Skip empty cells
            
            // Calculate the index of the sub-box
            int boxIndex = (row / 3) * 3 + (col / 3);
            
            // Check for duplicates in row, column, or box
            if (rowSets[row].count(num) || 
                colSets[col].count(num) || 
                boxSets[boxIndex].count(num)) {
                return false;
            }
            
            // Add the number to the respective sets
            rowSets[row].insert(num);
            colSets[col].insert(num);
            boxSets[boxIndex].insert(num);
        }
    }
    
    return true; // If no duplicates found, the board is valid
    }
};
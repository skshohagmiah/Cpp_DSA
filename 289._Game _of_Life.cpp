#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        // Directions for 8 neighbors
        vector<vector<int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1}, 
            {0, -1},          {0, 1}, 
            {1, -1}, {1, 0}, {1, 1}
        };
        
        // Step 1: Encode the intermediate states
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveNeighbors = 0;
                
                // Count live neighbors
                for (auto dir : directions) {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    
                    // Check bounds and count live neighbors (including -1 as live)
                    if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == -1)) {
                        liveNeighbors++;
                    }
                }
                
                // Apply rules
                if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[i][j] = -1; // Live -> Dead
                } else if (board[i][j] == 0 && liveNeighbors == 3) {
                    board[i][j] = 2;  // Dead -> Live
                }
            }
        }
        
        // Step 2: Decode the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -1) board[i][j] = 0; // Decode live to dead
                else if (board[i][j] == 2) board[i][j] = 1; // Decode dead to live
            }
        }
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;  // Tracks the furthest index we can reach
        
        for(int i = 0; i <= maxReach; i++) {
            // Stop if we've already determined we can reach the end
            if(maxReach >= nums.size() - 1) return true;
            
            // Update the furthest we can reach from current position
            maxReach = max(maxReach, i + nums[i]);
            
            // If we can't move forward anymore and haven't reached the end
            if(i == maxReach && i < nums.size() - 1) return false;
        }
        
        return true;
    }
};
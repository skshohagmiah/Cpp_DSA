class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) != map.end()) {
                // Check if the difference between indices is <= k
                if (i - map[nums[i]] <= k) {
                    return true;
                }
            }
            // Update the last seen index of the current number
            map[nums[i]] = i;
        }
        
        return false; // No valid pair found
    }
};

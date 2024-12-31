#include <vector>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int k = 1;  // Start from 1 since first element is always unique
        
        // Start from index 1
        for(int i = 1; i < nums.size(); i++) {
            // Compare with previous unique element (at k-1)
            if(nums[i] != nums[k-1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        
        return k;
    }
};
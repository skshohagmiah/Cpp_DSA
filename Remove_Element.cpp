#include <vector>
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;  // k will be the index where we place non-val elements
        
        // Go through each element in the array
        for(int i = 0; i < nums.size(); i++) {
            // If current element is not val
            if(nums[i] != val) {
                nums[k] = nums[i];  // Place it at position k
                k++;  // Move k to next position
            }
        }
        
        return k;  // k is now the count of elements not equal to val
    }
};
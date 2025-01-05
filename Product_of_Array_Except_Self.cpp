class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1); // Initialize result with all 1s
        
        // Step 1: Calculate the "left product" for each index
        int leftProduct = 1;
        for (int i = 0; i < n; ++i) {
            result[i] = leftProduct; // Store the product of all elements to the left
            leftProduct *= nums[i]; // Update the left product
        }

        // Step 2: Calculate the "right product" for each index and combine
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= rightProduct; // Multiply the current value with the right product
            rightProduct *= nums[i]; // Update the right product
        }

        return result;
    }
};

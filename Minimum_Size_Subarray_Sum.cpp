class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int n = nums.size();
       int maxLength = INT_MAX;
       int start = 0;
       int sum = 0;

       for(int end = 0; end < n; end++){
        sum += nums[end];

        while(sum >= target){
            maxLength = min(maxLength, (end - start) + 1);
            sum -= nums[start];
            start++;
        }
       }

       return maxLength == INT_MAX ? 0 : maxLength;
    }
};
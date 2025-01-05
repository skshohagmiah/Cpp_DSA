#include <vector>
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int curentMax = 0;
        int nextMax = 0;


        for(int i = 0; i < nums.size() - 1; i++){
            if(nums.size() <= 1) return 0;

            nextMax = max(nextMax, i + nums[i]);

            if( curentMax == i){
                jumps++;
                curentMax = nextMax;

                if(curentMax >= nums.size() - 1) break;
            }
        }
        return jumps;
    }
};
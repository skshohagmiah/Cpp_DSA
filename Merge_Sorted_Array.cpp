#include <vector>
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // Start from the last position of the final merged array
    int lastPos = m + n - 1;
    
    // Start from last elements of both arrays
    int i = m - 1;    // Last element of nums1
    int j = n - 1;    // Last element of nums2
    
    // Work backwards, putting larger elements at the end
    while (j >= 0) {  // While we still have elements in nums2 to process
        if (i >= 0 && nums1[i] > nums2[j]) {
            // If nums1 element is larger, put it at lastPos
            nums1[lastPos] = nums1[i];
            i--;
        } else {
            // If nums2 element is larger (or equal), or if we're done with nums1
            nums1[lastPos] = nums2[j];
            j--;
        }
        lastPos--;
    }
}
};
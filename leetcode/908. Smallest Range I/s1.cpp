// OJ: https://leetcode.com/problems/smallest-range-i/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxV = nums[0], minV = nums[0];
        
        for (int i: nums){
            maxV = max(maxV, i);
            minV = min(minV, i);
        }
        if (abs(maxV - minV) < (2 * k))
            return 0;
        else
            return abs(maxV - minV) - 2 * k;
    }
};

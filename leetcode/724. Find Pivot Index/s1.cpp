// OJ: https://leetcode.com/problems/find-pivot-index
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int r = accumulate(nums.begin(), nums.end(), 0), l = 0;
        for (int i = 0; i < nums.size(); i++){
            r -= nums[i];
            if (i > 0)
                l += nums[i - 1];
            if (l == r)
                return i;
        }
        return -1;
    }
};

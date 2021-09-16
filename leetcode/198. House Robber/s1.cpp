// OJ: https://leetcode.com/problems/house-robber/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        if (n == 1)
            return nums[0];
        for (int i = 0; i < n; i++){
            if (i > 1)
                nums[i] += nums[i-2];
            mx = max(mx, nums[i]);
            nums[i] = mx;
        }
        return max(nums[n-1], nums[n-2]);
    }
};

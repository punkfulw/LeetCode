// OJ: https://leetcode.com/problems/maximum-product-subarray/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = 0, curmin = 0, curmax = 0;
        if (nums.size() == 1) return nums[0];
        for (int i: nums){
            auto premax = curmax, premin = curmin;
            curmax = max(premin * i, max(i, curmax * i));
            curmin = min(premax * i, min(i, curmin * i));
            ans = max(ans, max(curmin, curmax));
        }
        return ans;
    }
};

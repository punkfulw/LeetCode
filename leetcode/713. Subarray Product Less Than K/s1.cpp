// OJ: https://leetcode.com/problems/subarray-product-less-than-k/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, n = nums.size(), l = 0, r = 0, p = 1;
        if (k == 0)
            return 0;
        
        for (; r < n; r++){
            p *= nums[r];
            while (l <= r && p >= k)
                p /= nums[l++];
            ans += r - l + 1;
        }
        return ans;
    }
};

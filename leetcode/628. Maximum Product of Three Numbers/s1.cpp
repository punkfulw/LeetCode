// OJ: https://leetcode.com/problems/maximum-product-of-three-numbers/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[0] * nums[1] * nums.back(), nums[n - 1] * nums[n - 2] * nums[n - 3]);
    }
};

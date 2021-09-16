// OJ: https://leetcode.com/problems/house-robber-ii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = nums[0];
        helper(nums, 0, nums.size()-1, ans);
        helper(nums, 1, nums.size(), ans);
        return ans;
    }
    void helper(vector<int>& nums, int start, int end, int &ans){
        int pp = 0, p = 0, cur = 0;
        for (int i = start; i < end; i++){
            cur = max(pp + nums[i], p);
            pp = p;
            p = cur;
        }
        ans = max(ans, cur);
    }
};

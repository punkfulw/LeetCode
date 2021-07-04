// OJ: https://leetcode.com/problems/build-array-from-permutation/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans (n);
        for (int i = 0; i < n; i ++)
            ans[i] = nums[nums[i]];
        return ans;
    }
};

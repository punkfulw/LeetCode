// OJ: https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int j = 0, n = nums.size();
        vector<int> ans = nums;
        
        for (int i = 0; i < n; i += 2)
            ans[i] = nums[j++];
        for (int i = 1; i < n; i += 2)
            ans[i] = nums[j++];
        return ans;
    }
};

// OJ: https://leetcode.com/problems/wiggle-subsequence/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int prev = 0, ans = 1;
        for (int i = 1; i < nums.size(); i++){
            int cur = nums[i] - nums[i - 1] == 0 ? 0 : nums[i] - nums[i - 1] < 0 ? -1 : 1;
            if (cur == 0) continue;
            if (prev == 0 || prev != cur) ans++;
            prev = cur;
        }
        
        return ans;
    }
};

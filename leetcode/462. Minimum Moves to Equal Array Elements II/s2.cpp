// OJ: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, l = 0, r = nums.size() - 1;
        while (l < r)
            ans += nums[r--] - nums[l++];

        return ans;
    }
};

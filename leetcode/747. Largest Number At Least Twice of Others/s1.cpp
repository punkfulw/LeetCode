// OJ: https://leetcode.com/problems/largest-number-at-least-twice-of-others/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        auto mx = max_element(nums.begin(), nums.end());
        for (auto i: nums){
            if (i == *mx)
                continue;
            if (*mx < 2 * i)
                return -1;
        }
        return mx - nums.begin();
    }
};

// OJ: https://leetcode.com/problems/moving-stones-until-consecutive/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> nums = {a, b, c};
        sort(nums.begin(), nums.end());
        a = nums[0], b = nums[1], c = nums[2];
        
        int mn = 2;
        if (c - b == 1 && b - a == 1)
            mn = 0;
        else if (c - b == 1 || b - a == 1 || c - b == 2 || b - a == 2)
            mn = 1;
            
        return {mn, c - a - 2};
    }
};

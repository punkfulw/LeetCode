// OJ: https://leetcode.com/problems/single-number/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i: nums)
            ans ^= i;
        return ans;
    }
};

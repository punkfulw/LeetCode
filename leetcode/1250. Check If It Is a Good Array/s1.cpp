// OJ: https://leetcode.com/problems/check-if-it-is-a-good-array/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/check-if-it-is-a-good-array/discuss/419368/JavaC%2B%2BPython-Chinese-Remainder-Theorem
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];
        for (int i: nums)
            g = gcd(g, i);
        return g == 1;
    }
};

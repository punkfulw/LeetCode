// OJ: https://leetcode.com/problems/binary-prefix-divisible-by-5/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size(), num = 0;
        vector<bool> ans(n, false);
        for (int i = 0; i < n; i++){
            num *= 2;
            num += nums[i];
            ans[i] = num % 5 == 0;
            num %= 10;
        }
        return ans;
    }
};

// OJ: https://leetcode.com/problems/maximum-xor-for-each-query/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int mx) {
        int n = nums.size(), k = (1 << mx) - 1;
        vector<int> ans(n);
        
        for (int i = 0; i < n; i++){
            nums[i] ^= i == 0 ? 0 : nums[i - 1];
            ans[n - i - 1] = nums[i] ^ k;
        }
        return ans;
    }
};

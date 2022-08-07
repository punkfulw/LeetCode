// OJ: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N) 
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int ttl = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i++)
            pre[i] = nums[i - 1] + pre[i - 1];
        for (int i = 0; i < n; i++){
            int l = pre[i + 1], r = pre[n] - pre[i + 1];
            nums[i] = (i + 1) * nums[i] - l + r - (n - i - 1) * nums[i];
        }
        return nums;
    }
};

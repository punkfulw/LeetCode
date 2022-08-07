// OJ: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1) 
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int ttl = accumulate(nums.begin(), nums.end(), 0), n = nums.size(), right = ttl;
        for (int i = 0; i < n; i++){
            int left = ttl - right, tmp = nums[i];
            nums[i] = i * nums[i] - left + right - (n - i) * nums[i];
            right -= tmp;
        }
        return nums;
    }
};

// OJ: https://leetcode.com/problems/k-radius-subarray-averages/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N) 
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long n = nums.size(), sum = 0, len = 2 * k + 1;
        vector<int> ans (n, -1);
        for (int i = 0; i < n; i++){
            sum += nums[i];
            if (i >= len)
                sum -= nums[i - len];
            if (i >= len - 1)
                ans[i - k] = sum / len;
        }
        return ans;
    }
};

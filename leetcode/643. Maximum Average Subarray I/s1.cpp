// OJ: https://leetcode.com/problems/maximum-average-subarray-i/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN, cnt = 0;
        for (int i = 0; i < nums.size(); i++){
            cnt += nums[i];
            if (i >= k)
                cnt -= nums[i - k];
            if (i >= k - 1)
                ans = max(ans, cnt);
        }
        return ans / k;
    }
};

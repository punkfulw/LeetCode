// OJ: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int n = nums.size(), ans = 0, cnt = 0, thres = threshold * k;
        for (int i = 0; i < n; i++){
            cnt += nums[i];
            if (i >= k)
                cnt -= nums[i - k];
            if (i >= k - 1 && cnt >= thres)
                ans++;
        }
        return ans;
    }
};

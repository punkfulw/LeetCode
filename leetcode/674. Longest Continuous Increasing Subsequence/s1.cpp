// OJ: https://leetcode.com/problems/longest-continuous-increasing-subsequence/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cnt = 1, ans = 0;     
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] > nums[i - 1])
                cnt++;
            else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        return max(ans, cnt);
    }
};

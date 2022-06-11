// OJ: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0), tar = sum - x, n = nums.size();
        if (tar < 0)
            return -1;
        int j = 0, cnt = 0, ans = INT_MAX;
        for (int i = 0; i < n; i++){
            cnt += nums[i];
            while (cnt > tar)
                cnt -= nums[j++];
            if (cnt == tar)
                ans = min(ans, n - (i - j + 1));
            
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

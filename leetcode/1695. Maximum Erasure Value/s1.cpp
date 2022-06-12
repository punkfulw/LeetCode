// OJ: https://leetcode.com/problems/maximum-erasure-value/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> presum (n + 1);
        for (int i = 0; i < n; i++){
            presum[i + 1] = nums[i];
            presum[i + 1] += presum[i];
        } 
        int i = 1, j = 1, ans = 0;
        unordered_map<int, int> mp;
        for (;i <= n; i++){
            int cur = nums[i - 1];
            if (mp[cur]){ 
                ans = max(ans, presum[i - 1] - presum[j - 1]);
                j = max(j, mp[cur] + 1);
            }
            mp[cur] = i;
        }
        ans = max(ans, presum[i - 1] - presum[j - 1]);
        return ans;
    }
};

// OJ: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
// Author: github.com/punkfulw
// Time: O(2^N * N)
// Space: O(N)
class Solution {
public:
    int mx, ans = 0, n;
    void dfs(int i, int x, vector<int>& nums){
        x |= nums[i];
        if (x == mx)
            ans++;
        for (int j = i + 1; j < n; j++)
            dfs(j, x, nums);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
        for (int i: nums)
            mx |= i;
        
        for (int i = 0; i < n; i++)
            dfs(i, 0, nums);
        return ans;
    }
};

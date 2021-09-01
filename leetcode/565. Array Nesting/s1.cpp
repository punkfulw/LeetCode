// OJ: https://leetcode.com/problems/array-nesting/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 1, n = nums.size();
        vector<int> cnt(n);
        for (int i = 0; i < n; i++){
            unordered_set<int> s;
            int cur = dfs(nums, cnt, i, s);
            ans = max(ans, cur);
        }
        return ans;
    }
    int dfs(vector<int>& nums, vector<int>& cnt, int start, unordered_set<int>& s){
        if (cnt[start] || s.count(nums[start]))
            return cnt[start];
        s.insert(nums[start]);
        int num = dfs(nums, cnt, nums[start], s);
        cnt[start] = num + 1;
        return num + 1 ;
    }
};

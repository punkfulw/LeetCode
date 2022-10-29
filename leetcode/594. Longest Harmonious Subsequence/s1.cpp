// OJ: https://leetcode.com/problems/longest-harmonious-subsequence/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mp;
        
        for (auto &i: nums)
            mp[i]++;
        
        for (auto &p: mp){
            int x = p.first, cnt = p.second;
            if (mp.find(x - 1) != mp.end())
                ans = max(ans, cnt + mp[x - 1]);
            if (mp.find(x + 1) != mp.end())
                ans = max(ans, cnt + mp[x + 1]);
        }
        return ans;
    }
};

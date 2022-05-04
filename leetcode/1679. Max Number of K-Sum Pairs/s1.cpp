// OJ: https://leetcode.com/contest/weekly-contest-218/problems/max-number-of-k-sum-pairs/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        map<int, int> mp, vis;
        
        for (auto i: nums)
        {
            if (i >= k)
                continue;
            mp[i]++;
        }  
        
        for (auto p: mp)
        {
            // cout << p.first << " " << p.second << endl;
            int cur = p.first, match = k - cur;
            if (vis[cur])
                continue;
            vis[cur] = vis[match] = 1;    
            ans += cur == match ? mp[cur] / 2 : min(mp[cur], mp[match]);
        }
        return ans;
    }
};

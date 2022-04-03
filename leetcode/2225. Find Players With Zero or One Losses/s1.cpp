// OJ: https://leetcode.com/problems/find-players-with-zero-or-one-losses/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) {
        map<int, int> l;
        set<int> app;
        
        for (auto g: mat)
        {
            int loser = g[1], winner = g[0];
            l[loser]++;
            app.insert(winner);
        }
        
        vector<vector<int>> ans(2);
        for (auto p: l)
        {
            if (p.second == 1)
                ans[1].push_back(p.first);
            app.erase(p.first);
        }
        
        for (auto i: app)
            ans[0].push_back(i);
        return ans;  
    }
};

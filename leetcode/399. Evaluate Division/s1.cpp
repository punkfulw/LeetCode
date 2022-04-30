// OJ: https://leetcode.com/problems/evaluate-division/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    
    map<string, vector<pair<string, double>>> mp;
    void dfs(string s1, string s2, map<string, int> &vis, double &cur, double run)
    {
        if (vis[s1]) return;
        vis[s1] = true;
        
        for (auto pair: mp[s1])
        {
            if (pair.first == s2)
            {
                cur = run * pair.second;
                return;
            }
            dfs(pair.first, s2, vis, cur, run * pair.second);
        }
        return;
    }
    
    vector<double> calcEquation(vector<vector<string>>& E, vector<double>& V, vector<vector<string>>& Q) {
        int n = Q.size(), m = E.size();
        vector<double> ans(n);
        
        for (int i = 0; i < m; i++)
        {
            string s1 = E[i][0], s2 = E[i][1];
            mp[s1].push_back({s2, V[i]});
            mp[s1].push_back({s1, 1});
            mp[s2].push_back({s1, 1 / V[i]});
            mp[s2].push_back({s2, 1});
        }
        
        for (int i = 0; i < n; i++)
        {
            string s1 = Q[i][0], s2 = Q[i][1];
            map<string, int> vis;
            double cur = -1;
            dfs(s1, s2, vis, cur, 1.0);
            ans[i] = cur;
        }
        return ans;
    }
};

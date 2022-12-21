// OJ: https://leetcode.com/problems/possible-bipartition/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int g1[2001] = {}, g2[2001] = {}, vis[2001] = {};
    vector<int> mp[2001];
    
    bool dfs(int i, int group){
        vis[i] = 1;
        if (group == 0)
            g1[i] = 1;
        else
            g2[i] = 1;
        
        int ret = 0, nxt_g = !group;
        for (auto nxt: mp[i]){
            if ((nxt_g == 0 && g2[nxt]) || (nxt_g == 1 && g1[nxt]))
                return true;
            if (!vis[nxt])
                ret |= dfs(nxt, nxt_g);
        }
        return ret;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for (auto p: dislikes){
            int a = p[0], b = p[1];
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        
        for (int i = 1; i <= n; i++)
            if (!vis[i])
                if (dfs(i, 0))
                    return false;

        return true;
    }
};

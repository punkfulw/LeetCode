// OJ: https://leetcode.com/problems/is-graph-bipartite/
// Author: github.com/punkfulw
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    void dfs(vector<vector<int>>& graph, map<int, int> &mp, int i, vector<int> &vis, bool &ans)
    {
        if (vis[i] || !ans)
            return;
        vis[i] = true;
        int group = mp[i] ? mp[i] : 0;
        int ones = 0, twos = 0;
        for (auto v: graph[i])
        {
            if (group)
            {
                if (mp[v] && mp[v] == group)
                {
                    ans = false;
                    return;
                }    
                mp[v] = group == 1 ? 2 : 1;
            }
            else
            {
                ones += mp[v] == 1;
                twos += mp[v] == 2;
            }
        }
        if (ones != 0 && twos != 0)
        {
            ans = false;
            return;
        }
            
        if (!group)
        {
            mp[i] = ones ? 2 : 1;
            for (auto v: graph[i])
                mp[v] = mp[i] == 1 ? 2 : 1;
        }     
        for (auto v: graph[i])
            dfs(graph, mp, v, vis, ans);
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        map<int, int> mp;
        vector<int> vis(n);
        bool ans = true;
        for (int i = 0; i < n; i++)
            dfs(graph, mp, i, vis, ans);
        return ans;
    }
};

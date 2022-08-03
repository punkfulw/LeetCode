// OJ: https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(E)
class Solution {
public:
    vector<vector<int>> mp;
    vector<vector<int>> ans;
    
    void dfs(int i, int j){
        for (auto nxt: mp[j]){
            if (ans[nxt].empty() || ans[nxt].back() != i){
                ans[nxt].push_back(i);
                dfs(i, nxt);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        ans.resize(n);
        mp.resize(n);
        for (auto e: edges)
            mp[e[0]].push_back(e[1]);
        
        for (int i = 0; i < n; i++)
            dfs(i, i);
        
        return ans;
    }
};

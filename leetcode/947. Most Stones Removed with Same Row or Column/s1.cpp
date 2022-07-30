// OJ: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:    
    unordered_map<int, vector<int>> row, col;
    
    void dfs(vector<vector<int>>& stones, vector<int> &vis, int i){
        vis[i] = 1;
        int r = stones[i][0], c = stones[i][1];
        for (auto nxt: row[r])
            if (!vis[nxt])
                dfs(stones, vis, nxt);
        for (auto nxt: col[c])
            if (!vis[nxt])
                dfs(stones, vis, nxt);
        return;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), ans = 0;
        vector<int> vis(n);
        
        for (int i = 0; i < n; i++){
            int r = stones[i][0], c = stones[i][1];
            row[r].push_back(i);
            col[c].push_back(i);
        }
        
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                dfs(stones, vis, i);
                ans++;
            }
        }
        return n - ans;
    }
};

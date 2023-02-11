// OJ: https://leetcode.com/problems/shortest-path-with-alternating-colors/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int n;
    vector<int> ans;
    vector<vector<int>> vis;
    vector<vector<vector<int>>> mp;  //red[0][i][nxt], blue [1][i][nxt]

    void sol(){
        queue<pair<int, int>> q;
        q.push({0, 0});  //0->red
        q.push({0, 1});  //1->blue
        int step = 0;
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                auto [idx, color] = q.front();
                q.pop();
                ans[idx] = min(ans[idx], step);
                int nxtColor = !color;
                for (auto nxt: mp[nxtColor][idx]){
                    if (vis[nxt][nxtColor])
                        continue;
                    vis[nxt][nxtColor] = 1;
                    q.push({nxt, nxtColor});
                }
            }
            step++;
        }
        return;
    }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        this->n = n;
        ans.resize(n, INT_MAX);
        vis.resize(n, vector<int> (2));
        mp.resize(2, vector<vector<int>>(n));
        
        for (auto E: redEdges){
            int a = E[0], b = E[1];
            mp[0][a].push_back(b);
        }
        
        for (auto E: blueEdges){
            int a = E[0], b = E[1];
            mp[1][a].push_back(b);
        }
        
        sol();
        for (auto &i: ans)
            if (i == INT_MAX)
                i = -1;
        return ans;
    }
};

// OJ: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> mp;
    int ans = 0;
    
    bool dfs(int node, int path, int pre, vector<bool>& hasApple){
        int ret = 0;
        if (hasApple[node]){
            ans += path * 2;
            path = 0;
            ret = 1;
        }

        for (auto nxt: mp[node])
            if (nxt != pre){
                ret |= dfs(nxt, path + 1, node, hasApple);
                if (ret == true) 
                    path = 0;
            }
        return ret;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        mp.resize(n);
        for (auto e: edges){
            int a = e[0], b = e[1];
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        dfs(0, 0, -1, hasApple);
        return ans;
    }
};

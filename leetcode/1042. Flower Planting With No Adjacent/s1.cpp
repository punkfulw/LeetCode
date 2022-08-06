// OJ: https://leetcode.com/problems/flower-planting-with-no-adjacent/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    unordered_map<int, vector<int>> mp;
    vector<int> ans;
    int n;
    
    bool dfs(int i, int pre){
        if (ans[i] == pre)
            return false;
        if (ans[i] != 0)
            return true;
        
        for (int col = 1; col <= 4; col++){
            bool found = 1;
            ans[i] = col;
            for (auto nxt: mp[i])
                found &= dfs(nxt, col);
            if (found)
                break;
            
        }
        return true; 
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        this->n = n;
        for (auto p: paths){
            mp[p[0]-1].push_back(p[1]-1);
            mp[p[1]-1].push_back(p[0]-1);
        }
        ans.resize(n, 0);
        for (int i = 0; i < n; i++){
            if (!ans[i])
                dfs(i, -1);
        }
        return ans;
        
    }
};

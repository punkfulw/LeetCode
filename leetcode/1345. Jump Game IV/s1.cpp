// OJ: https://leetcode.com/problems/jump-game-iv/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        vector<int> vis(n);
        
        for (int i = 0; i < n; i++){
            int x = arr[i];
            mp[x].push_back(i);
        }
        
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        int step = 0;
        
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                auto idx = q.front();
                q.pop();
                int cur = arr[idx];
                if (idx == n - 1)
                    return step;
                
                if (mp.find(cur) != mp.end()){
                    for (auto nxt: mp[cur]){
                        if (!vis[nxt]){
                            q.push(nxt);
                            vis[nxt] = 1; 
                        }
                    }
                }
                
                if (idx >= 1 && !vis[idx - 1]) {
                    q.push(idx - 1);
                    vis[idx - 1] = 1;
                }
                if (idx < n - 1 && !vis[idx + 1]) {
                    q.push(idx + 1);
                    vis[idx + 1] = 1;
                }
                mp.erase(cur);
            }
            step++;
        }  
        return 0;
    }
};

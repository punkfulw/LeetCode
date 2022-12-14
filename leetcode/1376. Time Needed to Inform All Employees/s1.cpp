// OJ: https://leetcode.com/problems/time-needed-to-inform-all-employees/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    unordered_map<int, vector<int>> mp;
    int ans = 0;
    
    void dfs(int root, int time, vector<int>& informTime){
        ans = max(ans, time);
        for (auto nxt: mp[root])
            dfs(nxt, time + informTime[nxt], informTime);
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {  
        for (int i = 0; i < n; i++)
            mp[manager[i]].push_back(i);
 
        dfs(headID, informTime[headID], informTime);
        return ans;
    }
};

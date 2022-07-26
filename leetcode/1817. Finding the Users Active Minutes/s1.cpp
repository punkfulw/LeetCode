// OJ: https://leetcode.com/problems/finding-the-users-active-minutes/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k);
        unordered_map<int, unordered_set<int>> mp;
        for (auto l: logs)
            mp[l[0]].insert(l[1]);
        
        for (auto p: mp){
            int cnt = p.second.size();
            ans[cnt - 1]++;
        }
        return ans;
    }
};

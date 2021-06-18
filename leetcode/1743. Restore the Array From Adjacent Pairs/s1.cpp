// OJ: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/discuss/1042989/C%2B%2B-Find-the-head
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ad) {

        unordered_map<int, vector<int>> mp;
        for (auto p:ad){
            mp[p[0]].push_back(p[1]);
            mp[p[1]].push_back(p[0]);
        }
        vector<int> ans;
        for (auto p: mp){
            if (p.second.size() == 1){
                ans.push_back(p.first);
                ans.push_back(p.second[0]);
                break;
            }
        }
        while (ans.size() < ad.size()+1){
            auto tail = ans.back(), pre = ans[ans.size()-2];
            auto next = mp[tail];
            if (next[0] != pre)
                ans.push_back(next[0]);
            else
                ans.push_back(next[1]);
        }
        return ans; 
    }
};

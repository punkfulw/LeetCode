// OJ: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/discuss/446534/C%2B%2BJava-Greedy
// Time: O(N)
// Space: O(N))
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        int n = g.size();
        vector<vector<int>> ans {};
        vector<vector<int>> cnt (n+1);
        
        for (int i = 0; i < n; i++){
            cnt[g[i]].push_back(i);
            if (cnt[g[i]].size() == g[i]){
                ans.push_back({});
                swap (ans.back(), cnt[g[i]]);
            }
        }
        return ans;
    }
};

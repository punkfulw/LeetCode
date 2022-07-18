// OJ: https://leetcode.com/problems/relative-ranks/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        vector<pair<int, int>> rk;
        for (int i = 0; i < n; i++)
            rk.push_back({score[i], i});
        sort(rk.rbegin(), rk.rend());

        for (int i = 0; i < n; i++){
            if (i == 0)
                ans[rk[i].second] = "Gold Medal";
            else if (i == 1)
                ans[rk[i].second] = "Silver Medal";
            else if (i == 2)
                ans[rk[i].second] = "Bronze Medal";
            else 
                ans[rk[i].second] = to_string(i + 1);
        }
        return ans;
    }
};

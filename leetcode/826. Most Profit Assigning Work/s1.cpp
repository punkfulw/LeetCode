// OJ: https://leetcode.com/problems/most-profit-assigning-work/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), ans = 0;
        vector<pair<int, int>> rec;

        for (int i = 0; i < n; i++)
            rec.push_back({difficulty[i], profit[i]});
        
        sort(rec.begin(), rec.end());
        sort(worker.begin(), worker.end());
        int i = 0, best = 0;
        
        for (auto &w: worker){
            while (i < n && rec[i].first <= w)
                best = max(best, rec[i++].second);
            ans += best;
        }
        
        return ans;
    }
};

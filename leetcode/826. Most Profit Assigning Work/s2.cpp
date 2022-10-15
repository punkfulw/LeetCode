// OJ: https://leetcode.com/problems/most-profit-assigning-work/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), m = worker.size(), ans = 0;
        
        map<int, int> mp;
        for (int i = 0; i < n; i++){
            int dif = difficulty[i], pro = profit[i];
            mp[dif] = max(mp[dif], pro);
        }
        mp[0] = 0;
        int mx = 0;
        for (auto &p: mp){
            mx = max(mx, p.second);
            p.second = mx;
            // cout << p.first << " " << p.second << endl;
        }
        
        for (auto &w: worker)
            ans += (--mp.upper_bound(w))->second;
        return ans;
    }
};

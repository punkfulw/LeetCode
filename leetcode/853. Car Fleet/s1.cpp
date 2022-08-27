// OJ: https://leetcode.com/problems/car-fleet/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int carFleet(double target, vector<int>& position, vector<int>& speed) {
        int n = position.size(), ans = 1;
        vector<pair<int, int>> rec;
        for (int i = 0; i < n; i++) rec.push_back({position[i], speed[i]});
        sort(rec.rbegin(), rec.rend());
        int prepos = rec[0].first, presp = rec[0].second;

        for (int i = 1; i < n; i++){
            int pos = rec[i].first, sp = rec[i].second;
            if (sp <= presp || (target - prepos) / presp < (target - pos) / sp){
                ans++;
                prepos = pos;
                presp = sp;
            }
        }
        return ans;
    }
};

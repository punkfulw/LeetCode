// OJ: https://leetcode.com/problems/maximum-units-on-a-truck/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int ts) {
        sort(box.begin(), box.end(), [](vector<int> &a, vector<int> &b){
            return a[1] > b[1];
        });
        int ans = 0, i = 0, n = box.size();
        while (ts && i < n){
            int take = min(ts, box[i][0]);
            ts -= take;
            ans += take * box[i++][1];
        }
        return ans;
    }
};

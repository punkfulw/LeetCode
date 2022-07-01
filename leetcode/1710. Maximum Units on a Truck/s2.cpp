// OJ: https://leetcode.com/problems/maximum-units-on-a-truck/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxs, int ts) {
        int ans = 0, i = 1000, n = boxs.size();
        int buckets[1001] = {};
        for (auto box: boxs)
            buckets[box[1]] += box[0];
        while (ts && i >= 0){
            if (buckets[i]){
                int take = min(ts, buckets[i]);
                ts -= take;
                ans += take * i;
            }
            i--; 
        }
        return ans;
    }
};

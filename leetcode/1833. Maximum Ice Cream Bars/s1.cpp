// OJ: https://leetcode.com/problems/maximum-ice-cream-bars/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int n = costs.size(), ans = 0;
        
        for (int i = 0; i < n and coins > 0; i++){
            coins -= costs[i];
            ans += coins >= 0;
        }
        return ans;
    }
};

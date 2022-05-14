// OJ: https://leetcode.com/problems/network-delay-time/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/743.%20Network%20Delay%20Time/README.md
// Time: O(VE)
// Space: O(V)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> costs(n + 1, INT_MAX);
        costs[k] = 0;
        for (int i = 1; i < n; i++)
        {
            for (auto &e: times)
            {
                int u = e[0], v = e[1], w = e[2];
                if (costs[u] == INT_MAX)
                    continue;
                costs[v] = min(costs[v], costs[u] + w);
            }    
        }
        
        int ans = *max_element(costs.begin() + 1, costs.end());
        return ans == INT_MAX ? -1 : ans;
    }
};

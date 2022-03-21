// OJ: https://leetcode.com/problems/reducing-dishes/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end());
        int mx = 0, n = sat.size();
        
        for (int i = 0; i < n; i++)
        {
            int cur = 0, cnt = 1;
            for (int j = i; j < n; j++)
            {
                cur += sat[j] * cnt;
                cnt++;
            }
            mx = max(mx, cur);
        }
        return mx;
    }
};

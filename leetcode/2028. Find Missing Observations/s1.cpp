// OJ: https://leetcode.com/problems/find-missing-observations/
// Author: github.com/punkfulw
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(), sum = accumulate(rolls.begin(), rolls.end(), 0), 
            ttl = mean * (n + m), remain = ttl - sum;
        double d = (double)remain / n;
        if (d > 6 || d < 1) return {};
        vector<int> ans(n);
        for (int i = 0; i < n; i++){
            ans[i] = (int)d;
            remain -= (int)d;
            if (i < n - 1)
                d = remain / (n - i - 1);
        }
        return ans;
    }
};

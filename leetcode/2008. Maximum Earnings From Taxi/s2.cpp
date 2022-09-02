// OJ: https://leetcode.com/problems/maximum-earnings-from-taxi/
// Author: github.com/punkfulw
// Time: O(N + M) 
// Space: O(N)
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<vector<pair<int, int>>> endAt(n + 1);
        
        for (auto r: rides){
            int start = r[0], end = r[1], tip = r[2];
            endAt[end].push_back({start, end - start + tip});
        }
        
        vector<long long> dp(n + 1);
        for (int pos = 1; pos <= n; pos++){
            for (auto r: endAt[pos]){
                dp[pos] = max(dp[pos], dp[r.first] + r.second);
            }
            dp[pos] = max(dp[pos], dp[pos - 1]);
        }
        return dp[n];
    }
};

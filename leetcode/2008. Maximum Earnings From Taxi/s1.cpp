// OJ: https://leetcode.com/problems/maximum-earnings-from-taxi/
// Author: github.com/punkfulw
// Time: O(NlogN) 
// Space: O(N)
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(), [](vector<int> &a, vector<int> &b){
            if (a[1] == b[1])
                return a < b;
            return a[1] < b[1];
        });
        
        vector<long long> dp(n + 1);
        for (int pos = 1, i = 0; pos <= n;){
            if (i < rides.size() && pos == rides[i][1]){
                dp[pos] = max(dp[pos], dp[rides[i][0]] + rides[i][2] + rides[i][1] - rides[i][0]);
                i++;
            }
            else{
                dp[pos] = max(dp[pos], dp[pos - 1]);
                pos++;
            }
        }
        return dp[n];
    }
};

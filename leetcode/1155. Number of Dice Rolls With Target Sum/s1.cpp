// OJ: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// Author: github.com/punkfulw
// Time: O(NK)
// Space: O(NK)
class Solution {
public:
    long MOD = 1e9 + 7;
    vector<vector<long>> dp;
    
    long dfs(int n, int K, int tar, int i, long cnt){
        if (n == i && cnt == tar)
            return 1;
        if (cnt > tar || n == i)
            return 0;
        if (dp[i][cnt] != -1)
            return dp[i][cnt];
        
        dp[i][cnt] = 0;
        for (int k = 1; k <= K; k++)
            dp[i][cnt] = (dp[i][cnt] + dfs(n, K, tar, i + 1, cnt + k)) % MOD; 

        return dp[i][cnt];
    }
    
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n, vector<long> (1001, -1));
        return dfs(n, k, target, 0, 0);
    }
};

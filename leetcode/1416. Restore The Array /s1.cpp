// OJ: https://leetcode.com/problems/restore-the-array/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    long long M = 1e9 + 7, n;
    long long dp[100005] = {};
    
    long long dfs(int i, string &s, int k){
        if (i == n)         
            return 1;   
        if (dp[i] != -1)    
            return dp[i];
        if (s[i] == '0' || s[i] - '0' > k) 
            return 0;
        
        long long ret = 0;
        
        for (long long j = 0, cnt = 0; i + j < n && cnt <= k; j++){
            cnt = cnt * 10 + (s[i + j] - '0');
            long long cur = 1;
            if (cnt <= k)
                cur = (cur * dfs(i + j + 1, s, k)) % M;
            else
                cur = 0;
            ret = (ret + cur) % M;
        }
        
        return dp[i] = ret;
    }
    
    int numberOfArrays(string s, int k) {
        n = s.size();
        memset(dp, -1, sizeof(dp));
        
        return dfs(0, s, k);
    }
};

// OJ: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/
// Author: github.com/punkfulw
// Time: O(MNK * max(M, N))
// Space: O(MNK)
class Solution {
public:
    int n, m, M = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    vector<vector<int>> pre;
    vector<string> s;
    
    int sol(int i, int j, int k){
        if (i >= n || j >= m)
            return 0;
        
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        
        if (k == 1)
            return pre[n][m] - pre[n][j] - pre[i][m] + pre[i][j] > 0;
        
        int ret = 0;
        for (int r = i, cnt = 0; r < n; r++)
            if (pre[r + 1][m] - pre[r + 1][j] - pre[i][m] + pre[i][j] > 0)
                ret = (ret + sol(r + 1, j, k - 1)) % M;
        
        for (int c = j; c < m; c++)
            if (pre[n][c + 1] - pre[i][c + 1] - pre[n][j] + pre[i][j] > 0)
                ret = (ret + sol(i, c + 1, k - 1)) % M;
        
        return dp[i][j][k] = ret;
    }
    
    int ways(vector<string>& s, int k) {
        n = s.size(), m = s[0].size();
        dp.resize(n, vector<vector<int>> (m, vector<int> (k + 1, -1)));
        pre.resize(n + 1, vector<int> (m + 1));
        this->s = s;
        
        for (int i = 0; i < n; i++)
            for (int j = 0, cnt = 0; j < m; j++){
                cnt += s[i][j] == 'A';
                pre[i + 1][j + 1] = pre[i][j + 1] + cnt;
            }
        return sol(0, 0, k);
    }
};

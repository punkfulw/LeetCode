// OJ: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
// Author: github.com/punkfulw
// Time: O(LM + LN)
// Space: O(LM)
class Solution {
public:
    int sz, m;
    long M = 1e9 + 7;
    vector<vector<int>> count, dp;
    
    long dfs(int idx, int k, vector<string> &words, string &tar){
        if (k == sz)
            return 1;
        if (idx >= m)
            return 0;
        
        if (dp[idx][k] != -1)
            return dp[idx][k];
        
        int ret = dfs(idx + 1, k, words, tar);
        
        if (count[idx][tar[k] - 'a'])
            ret = (ret + count[idx][tar[k] - 'a'] * dfs(idx + 1, k + 1, words, tar)) % M;
        
        return dp[idx][k] = ret;
    }
    
    int numWays(vector<string>& words, string target) {
        m = words[0].size(), sz = target.size();
        count.resize(m, vector<int> (26));    
        dp.resize(m + 1, vector<int> (sz + 1, -1)); 
        
        for (auto &w: words){
            for (int i = 0; i < m; i++)
                count[i][w[i] - 'a']++;
        }
        
        return dfs(0, 0, words, target);
    }
};

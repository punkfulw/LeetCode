// OJ: https://leetcode.com/problems/out-of-boundary-paths/
// Author: github.com/punkfulw
// Time: O(MNK)
// Space: O(MNK)
class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}}, MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    
    int dfs(int i, int j, int n, int m, int maxMove, int cnt){
        if (i < 0 || i >= n || j < 0 || j >= m)
            return 1;
        if (cnt == maxMove)
            return 0;
        if (dp[i][j][cnt] != -1)
            return dp[i][j][cnt];
        
        int ret = 0;
        for (int d = 0; d < 4; d++){
            int r = i + dirs[d][0], c = j + dirs[d][1];
            ret = (ret + dfs(r, c, n, m, maxMove, cnt + 1)) % MOD;
        }
        return dp[i][j][cnt] = ret;
    }
    int findPaths(int n, int m, int maxMove, int i, int j) {
        dp.resize(n, vector<vector<int>> (m, vector<int> (maxMove + 1, -1)));
        return dfs(i, j, n, m, maxMove, 0);
    }
};

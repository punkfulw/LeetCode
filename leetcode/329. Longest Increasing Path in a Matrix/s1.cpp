// OJ: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int dirs[5] = {1, 0, -1, 0, 1}, ans = 1, n, m;
    bool inbound(int i, int j){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    int dfs(int r, int c, vector<vector<int>>& length, vector<vector<int>>& mat){
        if (length[r][c])
            return length[r][c];
        int mxChildLen = 1;
         
        for (int k = 0; k < 4; k++){
            int i = r + dirs[k], j = c + dirs[k + 1], curChildLen = 1;
            if (inbound(i, j) && mat[i][j] > mat[r][c]){
                curChildLen += dfs(i, j, length, mat);   
                mxChildLen = max(mxChildLen, curChildLen);    
            }
            length[r][c] = mxChildLen;
        }         
        return length[r][c];
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        vector<vector<int>> length(n, vector<int> (m));
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!length[i][j])
                    ans = max(ans, dfs(i, j, length, mat));
        
        return ans;
    }
};

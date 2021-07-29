// OJ: https://leetcode.com/problems/01-matrix/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
    int m, n;
    int dirs[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        for (int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (mat[i][j] == 0)
                    ans[i][j] = 0;
                else
                    ans[i][j] = nearest(ans, i, j);
                if (mat[m-i-1][n-j-1] == 0)
                    ans[m-i-1][n-j-1] = 0;
                else
                    ans[m-i-1][n-j-1] = nearest(ans, m-i-1, n-j-1);
            }
        }
        return ans;
    }
    int nearest(vector<vector<int>>& ans, int i, int j){
        int res = INT_MAX;
        for (int k = 0; k < 4; k++){
            int x = i + dirs[k][0], y = j + dirs[k][1];
            if(x < 0 || x >= m || y < 0 || y >= n || ans[x][y] == INT_MAX)
                continue;
            if (ans[x][y] == 0)
                return 1;
            res = min(res, ans[x][y]+1);
        }
        return min(res, ans[i][j]);
    }
};

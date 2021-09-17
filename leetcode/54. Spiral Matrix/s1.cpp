// OJ: https://leetcode.com/problems/spiral-matrix
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans(n*m);
        int r = 0, c = 0, d = 0;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < n * m; i++){
            ans[i] = mat[r][c];
            mat[r][c] = -101;
            int nextR = r + dir[d % 4][0];
            int nextC = c + dir[d % 4][1];
            if (nextR >= n || nextR < 0 || nextC >= m || nextC < 0 || mat[nextR][nextC] < -100)
                d++;
            r += dir[d % 4][0], c += dir[d % 4][1];
        }
        return ans;
    }
};

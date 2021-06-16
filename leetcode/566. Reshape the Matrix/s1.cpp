// OJ: https://leetcode.com/problems/reshape-the-matrix/
// Author: github.com/punkfulw
// Time: O(N*M)
// Space: O(r*c)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        if (r * c != n * m)
            return mat;
        vector<vector<int>> ans(r, vector<int>(c));
        int row = 0, col = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                ans[row][col++] = mat[i][j];
                if (col == c){
                    col = 0;
                    row++;
                }
            }
        }
        return ans;
    }
};

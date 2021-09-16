// OJ: https://leetcode.com/problems/reshape-the-matrix/
// Author: github.com/punkfulw
// Time: O(N*M)
// Space: O(r*c)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        if (m * n != r * c)
            return mat;
        vector<vector<int>> ans (r, vector<int>(c));
        for (int i = 0, cnt = 0; i < r; i++)
            for (int j = 0; j < c; j++, cnt++)
                ans[i][j] = mat[cnt / m][cnt % m];
        return ans;
    }
};

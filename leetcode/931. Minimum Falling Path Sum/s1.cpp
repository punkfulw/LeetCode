// OJ: https://leetcode.com/problems/minimum-falling-path-sum/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int i = 1; i < n; i++){
            for (int j = 0; j < n; j++){
                int l = max(0, j - 1), r = min(n - 1, j + 1);
                mat[i][j] = mat[i][j] + min({mat[i - 1][l], mat[i - 1][j], mat[i - 1][r]});
            }
        }
        return *min_element(mat.back().begin(), mat.back().end());
    }
};

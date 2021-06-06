// OJ: https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        bool c[4];
        memset(c, true, sizeof(c));
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j] != target[i][j]) c[0] = false;
                if (mat[n-j-1][i] != target[i][j]) c[1] = false;
                if (mat[n-i-1][n-j-1] != target[i][j]) c[2] = false;
                if (mat[j][n-i-1] != target[i][j]) c[3] = false;
            }
        }
        return (c[0] || c[1] || c[2] || c[3]);
    }
};

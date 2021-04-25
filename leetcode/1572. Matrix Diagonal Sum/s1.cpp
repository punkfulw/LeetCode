// OJ: https://leetcode.com/problems/matrix-diagonal-sum/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int size = mat.size();
        int ans {};
        
        for (int i = 0, j = size-1; i < size; i++, j--){
            if (i == j)
                ans += mat[i][j];
            else
                ans += mat[i][i] + mat[i][j];
        }
        return ans;
    }
};

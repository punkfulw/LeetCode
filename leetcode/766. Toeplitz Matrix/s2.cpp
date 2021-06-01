// OJ: https://leetcode.com/problems/toeplitz-matrix/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> d(40, -1);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                int index = i - j + 20;
                if (d[index] == -1)
                    d[index] = matrix[i][j];
                else{
                    if (d[index] != matrix[i][j])
                        return false;
                }
            }
        }
        return true;
    }
};

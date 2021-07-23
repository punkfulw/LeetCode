// OJ: https://leetcode.com/problems/spiral-matrix-ii/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/59.%20Spiral%20Matrix%20II/README.md
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0, d = 1; i < n/2; i++){
            int len = n - 2*i - 1;
            for (int j = 0; j < len; j++) ans[i][i + j] = d++;
            for (int j = 0; j < len; j++) ans[i + j][n - i - 1] = d++;
            for (int j = 0; j < len; j++) ans[n - i - 1][n - i - j - 1] = d++;
            for (int j = 0; j < len; j++) ans[n - j - i - 1][i] = d++;
        }
        if (n%2)
            ans[n/2][n/2] = n*n;
        return ans;
    }
};

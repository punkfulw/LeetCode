// OJ: https://leetcode.com/problems/maximum-matrix-sum/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/1975.%20Maximum%20Matrix%20Sum/README.md
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int mn = 100001, cnt = 0;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j] < 0) cnt++;
                ans += abs(matrix[i][j]);
                mn = min(mn, abs(matrix[i][j]));
            }
        }
        return cnt % 2 ? ans - 2 * mn : ans;
    }
};

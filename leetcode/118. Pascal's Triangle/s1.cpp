// OJ: https://leetcode.com/problems/pascals-triangle/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/pascals-triangle/discuss/38171/Maybe-shortest-c%2B%2B-solution
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        
        for (int i = 0; i < numRows; i++){
            ans[i].resize(i+1);
            ans[i][0] = ans[i][i] = 1;
            for (int j = 1; j < i; j++)
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
        return ans;
    }
};

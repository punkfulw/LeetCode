// OJ: https://leetcode.com/problems/pascals-triangle/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> generate(int R) {
        vector<vector<int>> ans;
        for (int i = 1; i <= R; i++){
            ans.push_back(vector<int> (i, 1));
            if (i <= 2) continue;
            for (int j = 1; j < i - 1; j++){
                ans[i - 1][j] = ans[i - 2][j - 1] + ans[i - 2][j];
            }
        }
        return ans;
    }
};

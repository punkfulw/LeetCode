// OJ: https://leetcode.com/problems/n-queens-ii/
// Author: github.com/punkfulw
// Time: O(N!)
// Space: O(N)
class Solution {
public:
    vector<int> col, rdia, ldia;
    int dfs(int row, int n){
        if (row == n)
            return 1;
        int ans = 0;
        for (int j = 0; j < n; j++){
            if (!col[j] && !rdia[row + j] && !ldia[row - j + n - 1]){
                col[j] = rdia[row + j] = ldia[row - j + n - 1] = 1;
                ans += dfs(row + 1, n);
                col[j] = rdia[row + j] = ldia[row - j + n - 1] = 0;
            }
        }
        return ans;
    }
    
    int totalNQueens(int n) {
        col.resize(n), rdia.resize(2 * n - 1), ldia.resize(2 * n - 1);
        return dfs(0, n);
    }
};

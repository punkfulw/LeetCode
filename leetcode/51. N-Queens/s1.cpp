// OJ: https://leetcode.com/problems/n-queens/
// Author: github.com/punkfulw
// Time: O(N!)
// Space: O(N^2)
class Solution {
public:
    int n;
    vector<vector<string>> ans;
    vector<bool> rdia, ldia, row, col;
    
    void dfs(int i, vector<string>& cur){  
        if (i == n){
            ans.push_back(cur);
            return;
        }
        for (int c = 0; c < n; c++){
            if (!col[c] && !rdia[i + c] && !ldia[i - c + n - 1]){
                col[c] = rdia[i + c] = ldia[i - c + n - 1] = 1;
                cur[i][c] = 'Q';
                dfs(i + 1, cur);
                col[c] = rdia[i + c] = ldia[i - c + n - 1] = 0;
                cur[i][c] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int N) {
        n = N;
        rdia.resize(2 * n - 1, 0);
        ldia.resize(2 * n - 1, 0);
        row.resize(n, 0);
        col.resize(n, 0);
        vector<string> cur(n, string(n, '.'));
        
        dfs(0, cur);
        return ans;
    }
};

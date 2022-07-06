// OJ: https://leetcode.com/problems/where-will-the-ball-fall/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int n, m;
    int dfs(int i, int r, vector<vector<int>>& grid){
        if (r == n) return i;
        if (grid[r][i] == 1){
            if (i == m - 1 || grid[r][i + 1] == -1)
                return -1;
            return dfs(i + 1, r + 1, grid);
        }
        else {
            if (i == 0 || grid[r][i - 1] == 1)
                return -1;
            return dfs(i - 1, r + 1, grid);
        }
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < m; i++){
            int pos = dfs(i, 0, grid);
            ans.push_back(pos);
        }
        return ans;
    }
};

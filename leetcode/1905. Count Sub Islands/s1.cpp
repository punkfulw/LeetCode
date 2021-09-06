// OJ: https://leetcode.com/problems/count-sub-islands/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int n, m;
    int dirs[5] = {0, 1, 0, -1, 0};
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size(), m = grid1[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid2[i][j] == 1)
                    ans += dfs(grid1, grid2, i, j);
        return ans;
    }
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int row, int col){
        grid2[row][col] = 0;
        bool cover = true;
        if (!grid1[row][col])
            cover = false;
        for (int k = 0; k < 4; k++){
            int r = row + dirs[k], c = col + dirs[k+1];
            if (r >= 0 && r < n && c >= 0 && c < m && grid2[r][c]){
                bool next = dfs(grid1, grid2, r, c);
                cover = cover && next;
            }
        }
        return cover;
    }
};

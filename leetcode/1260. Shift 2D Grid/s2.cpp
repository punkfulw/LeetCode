// OJ: https://leetcode.com/problems/shift-2d-grid/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size(), ttl = m * n;
        k %= ttl;
        vector<vector<int>> ans = grid;
        for (int i = 0; i < ttl; i++)
        {
            int num = (i - k + ttl) % ttl;
            ans[i / m][i % m] = grid[num / m][num % m];
        }
        return ans;
    }
};

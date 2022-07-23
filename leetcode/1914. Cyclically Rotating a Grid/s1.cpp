// OJ: https://leetcode.com/problems/cyclically-rotating-a-grid/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(M + N)
class Solution {
public:
    int n, m;
    void sol(vector<vector<int>>& grid, vector<int> &nums, int r, int k){
        for (int i = r; i < n - r; i++)
            nums.push_back(grid[i][r]);
        for (int j = r + 1; j < m - r; j++)
            nums.push_back(grid[n - r - 1][j]);
        for (int i = n - r - 2; i >= r; i--)
            nums.push_back(grid[i][m - r - 1]);
        for (int j = m - r - 2; j > r; j--)
            nums.push_back(grid[r][j]);
        int sz = nums.size(), idx = 0;
        k %= sz;
        vector<int> arr = nums;
        for (int i = 0; i < sz; i++)
            arr[i] = nums[(i - k + sz) % sz];
        nums = arr;
        for (int i = r; i < n - r; i++)
            grid[i][r] = nums[idx++];
        for (int j = r + 1; j < m - r; j++)
            grid[n - r - 1][j] = nums[idx++];
        for (int i = n - r - 2; i >= r; i--)
            grid[i][m - r - 1] = nums[idx++];
        for (int j = m - r - 2; j > r; j--)
            grid[r][j] = nums[idx++];
    }
    
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        for (int r = 0; r < min(n, m) / 2 ; r++){
            vector<int> nums;
            sol(grid, nums, r, k);
        }
        return grid;
    }
};

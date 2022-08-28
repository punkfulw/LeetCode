// OJ: https://leetcode.com/problems/sort-the-matrix-diagonally/
// Author: github.com/punkfulw
// Time: O((N + M)DlogD), where D is the length of diagonal with D = min(M,N).
// Space: O(D)
class Solution {
public:
    int n, m;
    
    void  sol(int i, int j, vector<vector<int>> &mat){
        vector<int> nums;
        int x = i, y = j, idx = 0;
        while (i < n && j < m)
            nums.push_back(mat[i++][j++]);
        sort(nums.begin(), nums.end());
        while (x < n && y < m)
            mat[x++][y++] = nums[idx++];
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        for (int i = n - 1; i >= 0; i--)
            sol(i, 0, mat);
        for (int j = 1; j < m; j++)
            sol(0, j, mat);
        return mat;
    }
};

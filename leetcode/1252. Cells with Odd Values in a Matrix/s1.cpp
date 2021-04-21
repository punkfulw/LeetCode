// OJ: https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> count(m, vector<int>(n, 0));
        int ans {};
        
        for (int i = 0; i < indices.size(); i++){
            int row = indices[i].at(0);
            int col = indices[i].at(1);
            for (int c = 0; c < n; c++)
                count[row][c]++;
            for (int r = 0; r < m; r++)
                count[r][col]++;
        }
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++)
                if(count[i][j] % 2 != 0)
                    ans++;
        }
        return ans;
    }
};

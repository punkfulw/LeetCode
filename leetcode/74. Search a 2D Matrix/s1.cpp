// OJ: https://leetcode.com/problems/search-a-2d-matrix/
// Author: github.com/punkfulw
// Time: O(log(N)+log(M))
// Space: O(1)
class Solution {
public:
    bool findcol(vector<vector<int>>& mat, int target, int row) {
        int l = 0, r = mat[0].size() - 1;
        while (l <= r){
            int m = (l + r) / 2;
            if (mat[row][m] > target)
                r = m - 1;
            else if (mat[row][m] < target)
                l = m + 1;
            else
                return true;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int top = 0, bot = mat.size() - 1;
        int row = -1;
        while (top <= bot){
            int m = (top + bot) / 2;
            if (mat[m][0] < target){
                if (mat[m].back() >= target){
                    row = m;
                    break;
                }
                else
                    top = m + 1;
            }
            else if (mat[m][0] > target)
                bot = m - 1;   
            else 
                return true;
        }
        return row < 0 ? false : findcol(mat, target, row);
    }
};

// OJ: https://leetcode.com/problems/search-a-2d-matrix/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/74.%20Search%20a%202D%20Matrix/README.md
// Time: O(log(MN))
// Space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size(), l = 0, r = m * n - 1;
        while (l <= r){
            int mid = (l + r) / 2;
            if (mat[mid / m][mid % m] < target)
                l = mid + 1;
            else if (mat[mid / m][mid % m] > target)
                r = mid - 1;
            else
                return true;
        }
        return false;
    }
};

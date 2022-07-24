// OJ: https://leetcode.com/problems/search-a-2d-matrix-ii/
// Author: github.com/punkfulw
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n = nums.size(), m = nums[0].size(), i = 0, j = m - 1;
        while (i < n && j >= 0){
            if (nums[i][j] == target)
                return true;
            else if (nums[i][j] < target)
                i++;
            else 
                j--;
        }
        return false;
    }
};

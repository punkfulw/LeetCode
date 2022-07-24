// OJ: https://leetcode.com/problems/search-a-2d-matrix-ii/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int n, m;
    bool bs(int i, int j, vector<vector<int>>& nums, int target, int RorC){
        int l = 0, r = RorC == 0 ? n - 1 : m - 1;
        while (l <= r){
            int m = l + (r - l) / 2;      
            if (RorC){  
                if (nums[i][m] == target)
                    return true;
                else if (nums[i][m] < target)
                    l = m + 1;
                else 
                    r = m - 1;
            }
            else {
                if (nums[m][j] == target)
                    return true;
                else if (nums[m][j] < target)
                    l = m + 1;
                else 
                    r = m - 1;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        this->n = nums.size(), this->m = nums[0].size();
        for (int i = 0; i < n; i++)
            if (bs(i, 0, nums, target, 1))
                return true;
        
        for (int i = 0; i < m; i++)
            if (bs(0, i, nums, target, 0))
                return true;
        return false;
    }
};

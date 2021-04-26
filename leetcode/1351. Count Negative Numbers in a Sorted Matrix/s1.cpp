// OJ: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int size = (int)grid.size();
        int ans {};
        
        for (int i = 0; i < size; i++){
            int j = 0;
            while (j < grid[i].size() && grid[i][j] >= 0){
                j++;
            }
            ans += (int)grid[i].size()- j;
        }
        return ans;
    }
};

// OJ: https://leetcode.com/problems/max-increase-to-keep-city-skyline/
// Author: github.com/punkful
// Time: O(N^2)
// Space: O(N))
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int size = grid.size();
        int ans {};
        vector<int> row_max (size);
        vector<int> col_max (size);
        
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                if (grid[i].at(j) > row_max[i]){
                    row_max[i] = grid[i].at(j);
                }
                if (grid[j].at(i) > col_max[i]){
                    col_max[i] = grid[j].at(i);
                }
            }
        }
        
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                ans += max(min(row_max[i],col_max[j])- grid[i].at(j), 0) ;
            }
        }
        return ans;
    }
};

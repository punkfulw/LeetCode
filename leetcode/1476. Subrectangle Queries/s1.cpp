// OJ: https://leetcode.com/problems/subrectangle-queries/
// Author: github.com/punkfulw
// Time:
//      O(MN) for SubrectangleQueries and updateSubrectangle
//      O(1) for getValue
// Space: O(MN)
class SubrectangleQueries {
public:
    vector<vector<int>> nums;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        nums = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; i++)
            for (int j = col1; j <= col2; j++)
                nums[i][j] = newValue;
    }
    
    int getValue(int row, int col) {
        return nums[row][col];
    }
};

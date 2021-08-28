// OJ: https://leetcode.com/problems/spiral-matrix-iii/
// Author: github.com/punkfulw
// Time: O(max(R, C)^2)
// Space: O(R*C) for output
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int i, int j) {
        vector<vector<int>> ans;
        int cnt = 1, index = 0;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        ans.push_back({i, j});
        while (ans.size() < rows * cols){
            for (int r = 0; r < 2; r++){
                for (int k = 0; k < cnt; k++){
                    i += dir[index%4][0];
                    j += dir[index%4][1];
                    if (i < rows && j < cols && i >= 0 && j >= 0)
                        ans.push_back({i, j});
                }
                index++;
            }
            cnt++;
        }
        return ans;
    }
};

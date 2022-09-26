// OJ: https://leetcode.com/problems/largest-plus-sign/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int rec[501][501][4] = {}, ans = 0, nums[501][501] = {};
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                nums[i][j] = 1;
        for (auto mine: mines)
            nums[mine[0]][mine[1]] = 0;
        
        for (int i = 0; i < n; i++){
            int cntl = 0, cntr = 0, cntt = 0 , cntd = 0;
            for (int j = 0; j < n; j++){
                cntl = nums[i][j] == 0 ? 0 : cntl + 1;
                rec[i][j][0] = cntl;
                cntr = nums[i][n - 1 - j] == 0 ? 0 : cntr + 1;
                rec[i][n - j - 1][1] = cntr;
                cntt = nums[j][i] == 0 ? 0 : cntt + 1;
                rec[j][i][2] = cntt;
                cntd = nums[n - 1 - j][i] == 0 ? 0 : cntd + 1;
                rec[n - 1 - j][i][3] = cntd;
            }
        }
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++){
                int mn = min({rec[i][j][0], rec[i][j][1], rec[i][j][2], rec[i][j][3],});
                ans = max(ans, mn);
            }
        
        return ans;
    }
};

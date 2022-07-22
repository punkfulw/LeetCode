// OJ: https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/
// Author: github.com/punkfulw
// Time: O(M + N) 
// Space: O(1)
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int r = startPos[0] > homePos[0] ? -1 : 1;
        int c = startPos[1] > homePos[1] ? -1 : 1;
        int ans = 0;
        for (int i = startPos[0]; i != homePos[0]; i += r)
            ans += rowCosts[i + r];
        for (int i = startPos[1]; i != homePos[1]; i += c)
            ans += colCosts[i + c];
        return ans;
    }
};

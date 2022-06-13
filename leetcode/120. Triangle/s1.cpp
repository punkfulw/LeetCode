// OJ: https://leetcode.com/problems/triangle/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                tri[i][j] += min(tri[i + 1][j], tri[i + 1][j + 1]);
        return tri[0][0];
    }
};

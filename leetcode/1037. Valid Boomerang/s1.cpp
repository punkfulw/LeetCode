// OJ: https://leetcode.com/problems/valid-boomerang
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/valid-boomerang/discuss/286656/C%2B%2B-1-liner%3A-Triangle-Area
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& p) {
        return p[0][0] * (p[1][1] - p[2][1]) + p[1][0] * (p[2][1] - p[0][1]) + p[2][0] * (p[0][1] - p[1][1]);
    }
};

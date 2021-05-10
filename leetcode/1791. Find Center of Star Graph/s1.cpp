// OJ: https://leetcode.com/problems/find-center-of-star-graph/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int findCenter(vector<vector<int>>& E) {
        if (E[0][0] == E[1][0] || E[0][0] == E[1][1])
            return E[0][0];
        return E[0][1];
    }
};

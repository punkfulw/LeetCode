// OJ: https://leetcode.com/problems/escape-the-ghosts/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dis = abs(target[0]) + abs(target[1]);
        for (auto g: ghosts){
            int cur = abs(target[0] - g[0]) + abs(target[1] - g[1]);
            if (cur <= dis)
                return false;
        }
        return true;
    }
};

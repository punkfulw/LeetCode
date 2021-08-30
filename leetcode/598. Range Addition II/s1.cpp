// OJ: https://leetcode.com/problems/range-addition-ii/
// Author: github.com/punkfulw
// Time: O(ops) 
// Space: O(1)
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (auto op: ops){
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        return m * n;
    }
};

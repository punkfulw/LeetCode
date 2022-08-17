// OJ: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (auto op: operations)
            ans += op[1] == '+' ? 1 : -1;
        return ans;
    }
};

// OJ: https://leetcode.com/problems/a-number-after-a-double-reversal/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool isSameAfterReversals(int num) {
        return num == 0 ? 1 : num % 10;
    }
};

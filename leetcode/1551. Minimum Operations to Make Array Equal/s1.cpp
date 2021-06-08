// OJ: https://leetcode.com/problems/minimum-operations-to-make-array-equal/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int minOperations(int n) {
        if (n % 2 == 1)
            return (n / 2) * (2 + n - 1) / 2;
        else 
            return (n / 2) * (1 + n - 1) / 2;
    }
};

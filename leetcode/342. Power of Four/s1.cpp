// OJ: https://leetcode.com/problems/power-of-four/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool isPowerOfFour(long n) {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        if ((n ^ (n - 1)) == (n << 1) - 1 && __builtin_popcount(n - 1) % 2 == 0)
            return true;
        return false;
    }
};

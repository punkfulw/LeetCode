// OJ: https://leetcode.com/problems/complement-of-base-10-integer/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int bitwiseComplement(int n) {
        unsigned mask = ~0;
        if (n == 0)
            return 1;
        while (n & mask)
            mask <<= 1;
        return ~mask ^ n;
    }
};

// OJ: https://leetcode.com/problems/sum-of-two-integers/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary%3A-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (unsigned int)(a & b) << 1);
    }
};

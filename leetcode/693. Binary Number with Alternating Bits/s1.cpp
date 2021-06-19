// OJ: https://leetcode.com/problems/binary-number-with-alternating-bits/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        n = n ^ (n >> 2);
        return !(n & n-1);
    }
};

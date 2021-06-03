// OJ: https://leetcode.com/problems/complement-of-base-10-integer/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 1;
        while (n > mask)
            mask = mask * 2 + 1;
        return mask ^ n; 
    }
};

// OJ: https://leetcode.com/problems/sum-of-two-integers/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int carry =  (unsigned int)(a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};

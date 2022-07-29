// OJ: https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Author: github.com/punkfulw
// Time: O(logN) 
// Space: O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int recover = 0;
        while (left != right){
            recover++;
            left >>= 1;
            right >>= 1;
        }
        return left << recover;
    }
};

// OJ: https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Author: github.com/punkfulw
// Time: O(logN) 
// Space: O(logN)
class Solution {
public:
    int sol(int n){
        int ans = 0;
        while (n){
            ans++;
            n >>= 1;
        }
        return ans;
    }
    int rangeBitwiseAnd(int left, int right) {
        int a = sol(left), b = sol(right);
        if (a == 0 || b == 0) return 0;
        int highestBit = pow(2, a - 1);
        if (a == b)
            return highestBit + rangeBitwiseAnd(left - highestBit, right - highestBit);
        return 0;
    }
};

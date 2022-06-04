// OJ: https://leetcode.com/problems/powx-n/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(logN)
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n < 0)  return myPow(1 / x, -n);
        return (n % 2) ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2);
    }
};

// OJ: https://leetcode.com/problems/fibonacci-number/
// Author: github.com/punkfulw
// Time: O(2^n)
// Space: O(N)
class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        else
            return fib(n-1)+fib(n-2);
    }
};

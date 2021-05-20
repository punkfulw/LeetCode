// OJ: https://leetcode.com/problems/fibonacci-number/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        int ans = 0;
        int a = 0, b = 1;
        for (int i = 1; i < n; i++){
            ans = a + b;
            a = b;
            b = ans;
        }
        return ans;
    }
};

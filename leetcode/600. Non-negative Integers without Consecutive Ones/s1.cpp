// OJ: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/discuss/103754/C%2B%2B-Non-DP-O(32)-Fibonacci-solution
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int findIntegers(int n) {
        int ans = 0;
        int fib[32] = {};
        fib[0] = 1;
        fib[1] = 2;

        for (int i = 2; i < 32; i++)
            fib[i] = fib[i-1] + fib[i-2];
        
        int pre = 0;
        int k = 30;
        
        while (k >= 0){
            if (n & 1<<k){
                ans += fib[k];
                if (pre)
                    return ans;
                pre = 1;
            }
            else
                pre = 0;
            k--;
        }
        
        return ans + 1;
    }
};

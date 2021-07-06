// OJ: https://leetcode.com/problems/climbing-stairs/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1, c = 1;
        while (n){
            c = a + b;
            a = b;
            b = c;
            n--;
        }
        return c;
    }
};

// OJ: https://leetcode.com/problems/n-th-tribonacci-number/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int tribonacci(int n) {
        int fir = 0, sec = 1, thr = 1;
        if (n < 2) return n;
        if (n == 2) return 1;
        for (int i = 3; i <= n; i++){
            int cur =  fir + sec + thr;
            fir = sec; sec = thr; thr = cur;
        }        
        return thr;
    }
};

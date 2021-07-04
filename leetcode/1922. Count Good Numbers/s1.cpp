// OJ: https://leetcode.com/problems/count-good-numbers/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int countGoodNumbers(long long n) {
        int mod = 1e9 + 7;
        return (helper(5, (n + 1) / 2, mod) * helper(4, n / 2, mod)) % mod;
    }
    
    long long helper(int x, long long y, int mod){
        if (y == 0)
            return 1;
        long long a = helper(x, y/2, mod);
        if (y % 2)
            return (((x * a) % mod) * a) % mod;
        else
            return (a * a) % mod;
    }
};


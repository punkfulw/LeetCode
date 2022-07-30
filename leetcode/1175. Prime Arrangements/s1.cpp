// OJ: https://leetcode.com/problems/prime-arrangements/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    bool isPrime(int n){
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return false;
        return true;
    }
    int numPrimeArrangements(int n) {
        if (n <= 2) return 1;
        int mod = 1e9 + 7, ans = 1, cnt = 0;
        for (int i = 2; i <= n; i++)
            cnt += isPrime(i);
        long pnum = cnt ? 1 : 0, notP = n - cnt, npnum = notP ? 1 : 0;
        while (cnt)
            pnum = (pnum * cnt--) % mod;
        while (notP)
            npnum = (npnum * notP--) % mod;
        return (pnum * npnum) % mod;
    }
};

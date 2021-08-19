// OJ: https://leetcode.com/problems/the-kth-factor-of-n/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/the-kth-factor-of-n/discuss/708099/C%2B%2BJava-Straightforward-%2B-Sqrt(n)
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    int kthFactor(int n, int k) {
        int i = 1;
        for (; i * i <= n; i++)
            if (n % i == 0 && --k == 0)
                return i;
        if (--i * i == n) i--;
        for (; i >= 1; i--)
            if (n % i == 0 && --k == 0)
                return n / i;
        
        return -1;
    }
};

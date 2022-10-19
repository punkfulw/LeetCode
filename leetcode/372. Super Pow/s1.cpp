// OJ: https://leetcode.com/problems/super-pow/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        long long MOD = 1337, n = b.size(), ans = 1;
        a %= MOD;
        for (int i = 0; i < n; i++){
            long long m = b[i], mul = 1;
            for (int j = 0; j < m; j++)
                mul = (mul * a) % MOD;
            int pre = ans;
            for (int d = 0; d < 9; d++)
                ans = (ans * pre) % MOD;

            ans = (ans * mul) % MOD;
        }
        return ans;
    }
};

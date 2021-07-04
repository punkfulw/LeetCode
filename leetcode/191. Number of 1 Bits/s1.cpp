// OJ: https://leetcode.com/problems/number-of-1-bits/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n > 0){
            ans += n % 2;
            n /= 2;
        }
        return ans;
    }
};

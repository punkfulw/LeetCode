// OJ: https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/
// Author: github.com/punkfulw
// Time: O(Nlog(max(A)))
// Space: O(1)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, mx = 1;
        for (auto i: nums){
            int bits = 0;
            while (i){
                ans += (i & 1);
                i >>= 1;
                bits++;
            }
            mx = max(mx, bits);
        }
        return ans + mx - 1;
    }
};

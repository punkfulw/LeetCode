// OJ: https://leetcode.com/problems/counting-bits
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans (n+1, 0);
        for (int i = 1; i <= n; i++){
            ans[i] = ans[i & (i-1)] + 1;
        }
        return ans;
    }
};

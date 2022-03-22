// OJ: https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/1663.%20Smallest%20String%20With%20A%20Given%20Numeric%20Value/README.md
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k -= n;
        
        for(int i = n - 1; i >= 0; i--)
        {
            int cur = min(k, 25);
            ans[i] += cur;
            k -= cur;
        }
        return ans;
    }
};

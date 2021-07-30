// OJ: https://leetcode.com/problems/excel-sheet-column-number/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
            ans = ans * 26 + (s[i] - 'A' + 1);
        return ans;
    }
};

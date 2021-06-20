// OJ: https://leetcode.com/problems/largest-odd-number-in-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size()-1; i >= 0; i--)
            if ((num[i] - '0') % 2)
                return num.substr(0, i+1);
        return "";
    }
};

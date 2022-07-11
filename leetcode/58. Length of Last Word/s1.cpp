// OJ: https://leetcode.com/problems/length-of-last-word/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, pos = s.size() - 1;
        while (s[pos] == ' ')
            pos--;
        while (pos >= 0 && s[pos] != ' '){
            ans++;
            pos--;
        }
        return ans;
    }
};

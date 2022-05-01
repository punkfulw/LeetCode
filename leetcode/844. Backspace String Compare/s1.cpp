// OJ: https://leetcode.com/problems/backspace-string-compare/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        int ix = 0, jx = 0;
        while (true)
        {
            while (i >= 0 && (ix || s[i] == '#'))
            {
                s[i] == '#'? ix++ : ix--;
                i--;
            }
            
            while (j >= 0 && (jx || t[j] == '#'))
            {
                t[j] == '#'? jx++ : jx--;
                j--;
            }
            
            if (i < 0 || j < 0 || s[i] != t[j])
                break;
            i--, j--;
        }
        return i == -1 && j == -1;
    }
};

// OJ: https://leetcode.com/problems/minimum-window-substring/
// Author: github.com/punkfulw
// Ref: https://discuss.leetcode.com/topic/30941/here-is-a-10-line-template-that-can-solve-most-substring-problems
// Time: O(N)
// Space: O(C) where C is the range of characters
class Solution {
public:
    string minWindow(string s, string t) {
        int m[128] = {};
        for (char c : t) ++m[c];
        int begin = 0, end = 0, head = 0, cnt = t.size(), len = INT_MAX;
        while (end < s.size()) {
            if (--m[s[end++]] >= 0) --cnt;
            while (!cnt) {
                if (end - begin < len) len = end - (head = begin);
                if (++m[s[begin++]] > 0) ++cnt;
            }
        }
        return len == INT_MAX ? "" : s.substr(head, len);
    }
};

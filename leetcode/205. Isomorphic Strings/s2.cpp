// OJ: https://leetcode.com/problems/isomorphic-strings/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/205.%20Isomorphic%20Strings/README.md
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m, r;
        for (int i = 0; i < s.size(); ++i) {
            if (m.count(s[i]) && m[s[i]] != t[i]) return false;
            if (r.count(t[i]) && r[t[i]] != s[i]) return false;
            m[s[i]] = t[i];
            r[t[i]] = s[i];
        }
        return true;
    }
};

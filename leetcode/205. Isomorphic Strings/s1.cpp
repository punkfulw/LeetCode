// OJ: https://leetcode.com/problems/isomorphic-strings/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/isomorphic-strings/discuss/57796/My-6-lines-solution
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};

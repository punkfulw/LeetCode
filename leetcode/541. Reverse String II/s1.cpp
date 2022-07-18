// OJ: https://leetcode.com/problems/reverse-string-ii
// Author: github.com/punkfulw
// Time: O(NN)
// Space: O(1)
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k)
            reverse(s.begin() + i, s.begin() + min(n, i + k));
        return s;
    }
};

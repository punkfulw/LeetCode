// OJ: https://leetcode.com/problems/make-the-string-great/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/make-the-string-great/discuss/780897/C%2B%2B-Brute-Force-%2B-Two-Pointers
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string makeGood(string s) {
        int p = 0;
        for (int i = 0; i < s.size(); i++){
            if (p > 0 && abs(s[i] - s[p - 1]) == 32)
                p--;
            else
                s[p++] = s[i];
        }
        return s.substr(0, p);
    }
};

// OJ: https://leetcode.com/problems/greatest-common-divisor-of-strings/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/greatest-common-divisor-of-strings/discuss/307242/C%2B%2B-3-lines
// Time: O(logN) 
// Space: O(1)
class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        return s1 + s2 == s2 + s1 
            ? s1.substr(0, gcd(s1.size(), s2.size()))
            : "";
    }
};

// OJ: https://leetcode.com/problems/rotate-string/
// Author: github.com/punkfulw
// Time: O(N ^ N)
// Space: O(1)
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size(), m = n;
        while (m--){
            if (s == goal)
                return true;
            s = s.substr(1, n - 1) + s[0];
        }
        return false;
    }
};

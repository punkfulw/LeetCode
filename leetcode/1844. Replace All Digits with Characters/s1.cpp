// OJ: https://leetcode.com/problems/replace-all-digits-with-characters/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 1; i < s.size(); i += 2){
            s[i] = s[i-1] + s[i] - '0';
        }
        return s;
    }
};

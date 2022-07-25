// OJ: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
// Author: github.com/punkfulw
// Time: O(NW)
// Space: O(1)
class Solution {
public:
    bool check(string &s){
        int i = 0, j = s.size() - 1;
        while (i < j){
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for (auto s: words)
            if (check(s))
                return s;
        return "";
    }
};

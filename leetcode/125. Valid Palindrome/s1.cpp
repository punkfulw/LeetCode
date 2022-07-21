// OJ: https://leetcode.com/problems/valid-palindrome/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isPalindrome(string S) {
        string s;
        for (auto c: S){
            if (isalpha(c))
                s += tolower(c);
            if (isdigit(c))
                s += c;
        }
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            if (s[i] != s[j])
                return false;
        return true;
    }
};

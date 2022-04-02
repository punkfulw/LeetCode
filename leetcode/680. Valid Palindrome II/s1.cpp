// OJ: https://leetcode.com/problems/valid-palindrome-ii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool check(int l, int r, string s)
    {
        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++; r--;
                continue;
            }
            return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++; r--;
                continue;
            }  
            return check(l, r-1, s) || check(l+1, r, s);
        }
        return true;
    }
};

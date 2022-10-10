// OJ: https://leetcode.com/problems/break-a-palindrome/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.size(), pos = -1;
        if (n == 1)
            return "";
        
        for (int i = 0; i < n / 2; i++){
            if (s[i] != 'a'){
                pos = i;
                break;
            }
        }
        
        if (pos == -1)
            s[n - 1] = 'b';
        else 
            s[pos] = 'a';
        return s;
    }
};

# OJ: https://leetcode.com/problems/valid-palindrome-ii/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def checkP(self, s, l, r):
        while (l < r):
            if (s[l] == s[r]):
                l += 1
                r -= 1
                continue
            return False
        return True
            
    def validPalindrome(self, s: str) -> bool:
        l, r = 0, len(s)-1
        while (l < r):
            if (s[l] == s[r]):
                l += 1
                r -= 1
                continue
            return self.checkP(s, l+1, r) or self.checkP(s, l, r-1)
        return True
    

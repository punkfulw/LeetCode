# OJ: https://leetcode.com/problems/reverse-only-letters/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        i, j = 0, len(s)-1
        s = list(s)
        while i < j:
            while i < j and not s[i].isalpha():
                i += 1
            while i < j and not s[j].isalpha():
                j -= 1
            s[i], s[j] = s[j], s[i]
            i, j = i + 1, j - 1
        return "".join(s)

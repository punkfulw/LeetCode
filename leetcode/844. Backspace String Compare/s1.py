# OJ: https://leetcode.com/problems/backspace-string-compare/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        i, j = len(s) - 1, len(t) - 1 
        ix, jx = 0, 0
        
        while True:
            while i >= 0 and (ix or s[i] == '#'):
                if s[i] == '#':
                    ix += 1
                else: 
                    ix -= 1
                i -= 1
            while j >= 0 and (jx or t[j] == '#'):
                if t[j] == '#':
                    jx += 1
                else: 
                    jx -= 1
                j -= 1
            if (i < 0 or j < 0 or s[i] != t[j]):
                break;
            i -= 1
            j -= 1
        return i == -1 and j == -1

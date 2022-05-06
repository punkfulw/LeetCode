# OJ: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(N)
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stk = []
        for c in s:
            if len(stk) == 0 or stk[-1][0] != c:
                stk.append([c, 1])
            else:
                stk[-1][1] += 1
                if (stk[-1][1] == k):
                    stk.pop()
        return "".join(c * k for c, k in stk)
            
                

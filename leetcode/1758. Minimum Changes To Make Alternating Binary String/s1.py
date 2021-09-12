// OJ: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution:
    def minOperations(self, s: str) -> int:
        d1 = d2 = 0
        for i in range(len(s)):
            if i % 2:
                if s[i]=='0': d1 += 1
                else: d2 += 1
            else:
                if s[i]=='1': d1 += 1
                else: d2 += 1
        return min(d1, d2)

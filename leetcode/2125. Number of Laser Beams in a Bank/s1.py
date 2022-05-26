# OJ: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
# Author: github.com/punkfulw
# Time: O(MN)
# Space: O(1)
class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        ans = prev = 0
        for r in bank:
            cur = r.count('1')
            if cur == 0:
                continue
            ans += cur * prev
            prev = cur
        return ans

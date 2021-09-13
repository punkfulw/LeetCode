# OJ: https://leetcode.com/problems/first-bad-version/
# Author: github.com/punkfulw
# Time: O(logN)
# Space: O(1)
class Solution:
    def firstBadVersion(self, n):
        l, r = 1, n
        while l <= r:
            m = (r - l) // 2 + l
            if isBadVersion(m):
                r = m - 1
            else:
                l = m + 1
        return l

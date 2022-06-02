# OJ: https://leetcode.com/problems/transpose-matrix/
# Author: github.com/punkfulw
# Time: O(MN)
# Space: O(1)
class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        return list(zip(*matrix))

# OJ: https://leetcode.com/problems/last-stone-weight/
# Author: github.com/punkfulw
# Time: O(NlogN)
# Space: O(1)
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        for i, s in enumerate(stones):
            stones[i] = -s
        heapify(stones)
        while len(stones) > 1:
            f, s = -heappop(stones), -heappop(stones)
            if f - s > 0:
                heappush(stones, s - f)
        if not stones:
            return 0
        return -stones[0]
            

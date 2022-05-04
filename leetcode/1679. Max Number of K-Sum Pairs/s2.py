# OJ: https://leetcode.com/problems/max-number-of-k-sum-pairs/
# Author: github.com/punkfulw
# Ref: https://leetcode.com/problems/max-number-of-k-sum-pairs/discuss/1023235/C%2B%2B4-approaches-a-variation-of-two-sum
# Time: O(N)
# Space: O(N)
class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        mp = defaultdict(int)
        ans = 0
        for i in nums:
            if i >= k:
                continue
            match = k - i
            if mp[match] >= 1:
                ans += 1
                mp[match] -= 1
            else:
                mp[i] += 1
        return ans

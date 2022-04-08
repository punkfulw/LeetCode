# OJ: https://leetcode.com/problems/kth-largest-element-in-a-stream/
# Author: github.com/punkfulw
# Time:
#     KthLargest: O(NlogK)
#     add: O(logK)
# Space: O(N)
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.nums = nums
        self.k = k
        heapify(nums)
        while len(self.nums) > k:
            heappop(self.nums)

    def add(self, val: int) -> int:
        heappush(self.nums, val)
        if len(self.nums) > self.k:
            heappop(self.nums)
        return self.nums[0]

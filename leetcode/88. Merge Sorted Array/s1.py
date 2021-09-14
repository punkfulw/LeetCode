# OJ: https://leetcode.com/problems/merge-sorted-array/
# Author: github.com/punkfulw
# Time: O(M + N)
# Space: O(1)
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        p = m - 1
        q = n - 1
        i = m + n - 1
        while p >= 0 and q >= 0:
            if nums1[p] >= nums2[q]:
                nums1[i] = nums1[p]
                p -= 1
            else:
                nums1[i] = nums2[q]
                q -= 1
            i -= 1
        while q >= 0:
            nums1[i] = nums2[q]
            q -= 1
            i -= 1

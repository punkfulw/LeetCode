# OJ: https://leetcode.com/problems/intersection-of-two-arrays-ii/
# Author: github.com/punkfulw
# Time: O(NlogN)
# Space: O(1)
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        i = j = 0
        ans = []
        nums1, nums2 = sorted(nums1), sorted(nums2)
        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                ans.append(nums1[i])
                i, j = i + 1, j + 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
        return ans;

# OJ: https://leetcode.com/problems/search-in-a-binary-search-tree/
# Author: github.com/punkfulw
# Time: O(H)
# Space: O(1)
class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        p = root
        while p != None:
            if p.val == val:
                return p
            elif p.val < val:
                p = p.right
            else:
                p = p.left
        return p

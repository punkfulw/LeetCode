# OJ: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(H)
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        stk = []
        while root or len(stk):
            while root:
                stk.append(root)
                root = root.left
            cur = stk.pop()
            k -= 1
            if (k == 0):
                return cur.val
            root = cur.right

# OJ: https://leetcode.com/problems/invert-binary-tree/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(H)
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root == None:
            return None
        root.left, root.right = root.right, root.left
        self.invertTree(root.left)
        self.invertTree(root.right)
        return root

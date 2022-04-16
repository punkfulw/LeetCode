# OJ: https://leetcode.com/problems/convert-bst-to-greater-tree/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(H)
class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.cnt = 0
        def find(root):
            if root == None:
                return 
            find(root.right)
            self.cnt += root.val
            root.val = self.cnt
            find(root.left)
        find(root)
        return root

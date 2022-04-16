# OJ: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(N)
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
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

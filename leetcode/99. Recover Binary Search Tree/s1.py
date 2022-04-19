# OJ: https://leetcode.com/problems/recover-binary-search-tree/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(H)
class Solution:
    first = second = prev = None
    def inorder(self, root):
        if root == None:
            return 
        self.inorder(root.left)
        if (self.prev and self.prev.val > root.val):
            if self.first == None:
                self.first = self.prev
            self.second = root
        self.prev = root
        self.inorder(root.right)
        
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        self.inorder(root)
        self.first.val, self.second.val = self.second.val, self.first.val 
        

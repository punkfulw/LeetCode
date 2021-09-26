# OJ: https://leetcode.com/problems/path-sum/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(H)
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root == None:
            return False
        targetSum -= root.val
        if root.left == None and root.right == None and targetSum == 0:
            return True
        return self.hasPathSum(root.left, targetSum) or self.hasPathSum(root.right, targetSum)
